Map.addLayer(ROI);
Map.centerObject(ROI, 10); // 10 sets it to center the ROI

var L9 = ee.ImageCollection("MODIS/061/MCD43A4"); // Grab data from Landsat
// var L9 = ee.ImageCollection("LANDSAT/LC09/C02/T1_L2") // Grab data from Landsat

var image = L9.filterBounds(ROI).filterDate('2022-03-01', '2022-03-31').filterMetadata('CLOUD_COVER', 'less_than', 1).median().clip(ROI)

Map.addLayer(image, imageVisParam)

var sample = BuiltupArea.merge(CropLand).merge(ScrubArea).merge(Waterbodies).merge(HarvestedCrop);

print(sample);

var bands = ['B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7']
var classProperty = 'Class'

var training = image.select(bands).sampleRegions({
    collection: sample,
    properties: [classProperty],
    scale: 30
});

print(training);

var classifier = ee.Classifier.smileCart().train({
    features: training,
    classProperty: classProperty,
    inputProperties: bands
});

print(classifier.getInfo());

var classified = image.select(bands).classify(classifier);

Map.addLayer(classified, { min: 0, max: 4, pallette: ['blue', 'green', 'yellow', 'red', 'magenta'] });

// var withRandom = training.randomColumn('random');

// var split = 0.7;
// var trainingPartition = withRandom.filter(ee.Filter.lt('random', split));
// var testingPartition = withRandom.filter(ee.Filter.gte('random', split));

// var trainedClassifier = ee.Classifier.smileCart().train({
//     features: trainingPartition,
//     classProperty: classProperty,
//     inputProperties: bands
// })

// var test = testingPartition.classify(trainedClassifier);

// var confusionMatrix = test.errorMatrix(classProperty, 'classified');

// print('Confusion Matrix', confusionMatrix);

// Export.image.toDrive({
//     image: classified,
//     description: 'LULC',
//     maxPixels: 1e13,
//     region: ROI,
//     scale: 30
// });

var sample_rc = training.randomColumn('rand');
var training = sample_rc.filter(ee.Filter.lt('rand', 0.7));
var validation = sample_rc.filter(ee.Filter.gte('rand', 0.7));

var classifier = ee.Classifier.smileCart().train({
    features: training,
    classProperty: classProperty,
    inputProperties: bands
});

var confusionMatrix = ee.ConfusionMatrix(validation.classify(classifier).errorMatrix(
    {
        actual: classProperty,
        predicted: 'classification'
    }
));

print('Confusion Matrix', confusionMatrix);
print('Overall Accuracy', confusionMatrix.accuracy());


