// ROI - Region of Interest i.e. Bangalore
Map.addLayer(ROI)
Map.centerObject(ROI, 10)

// L9 - Landsat 9 Data
var image = L9.filterBounds(ROI).filterDate('2023-01-01', '2023-12-31').filterMetadata('CLOUD_COVER', 'less_than', 1).median().clip(ROI)

Map.addLayer(image)

var sample = BuiltupArea.merge(Other);

print(sample);

var bands = ['B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7']
var classProperty = 'Class'

// Creating training data
var training = image.select(bands).sampleRegions({
    collection: sample,
    properties: [classProperty],
    scale: 30
});

print(training);

// Training the classifier
var classifier = ee.Classifier.smileCart().train({
    features: training,
    classProperty: classProperty,
    inputProperties: bands
});

print(classifier.getInfo());

var classified = image.select(bands).classify(classifier);

Map.addLayer(classified, { min: 0, max: 1, pallette: ['blue', 'green', 'yellow', 'red', 'magenta'] });

// Creating smaller dataset
var withRandom = training.randomColumn('random');

var split = 0.7;
var trainingPartition = withRandom.filter(ee.Filter.lt('random', split));
var testingPartition = withRandom.filter(ee.Filter.gte('random', split));

var trainedClassifier = ee.Classifier.smileCart().train({
    features: trainingPartition,
    classProperty: classProperty,
    inputProperties: bands
})

var test = testingPartition.classify(trainedClassifier);

var confusionMatrix = test.errorMatrix(classProperty, 'classified');

print('Confusion Matrix 1', confusionMatrix);

// Accuracy Assessment
var sample_rc = training.randomColumn('rand');
var training = sample_rc.filter(ee.Filter.lt('rand', 0.7));
var validation = sample_rc.filter(ee.Filter.gte('rand', 0.7));

var confusionMatrix = ee.ConfusionMatrix(validation.classify(classifier).errorMatrix(
    {
        actual: classProperty,
        predicted: 'classification'
    }
));

print('Confusion Matrix', confusionMatrix);
print('Overall Accuracy', confusionMatrix.accuracy());

// Exporting the classified image
Export.image.toDrive({
    image: classified,
    description: 'Bangalore-2023-Classified',
    maxPixels: 1e13,
    region: ROI,
    scale: 30
});