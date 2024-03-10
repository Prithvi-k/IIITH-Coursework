Map.addLayer(ROI);
Map.centerObject(ROI, 10);

var L9 = ee.ImageCollection("MODIS/061/MCD43A4");

var image = L9.filterBounds(ROI).filterDate('2022-03-01', '2022-03-31').median().clip(ROI)

var trueColor = image.select([
    'Nadir_Reflectance_Band1', 'Nadir_Reflectance_Band2', 'Nadir_Reflectance_Band4',
    'Nadir_Reflectance_Band3', 'Nadir_Reflectance_Band5',
    'Nadir_Reflectance_Band6', 'Nadir_Reflectance_Band7'
]);
var trueColorVis = {
    min: 0.0,
    max: 4000.0,
    gamma: 1.4,
};
Map.setCenter(-7.03125, 31.0529339857, 2);
Map.addLayer(trueColor, trueColorVis, 'True Color');

print("added modis dataset");

var sample = water.merge(builtup).merge(vegetation).merge(arid);

print(sample);

var bands = ['Nadir_Reflectance_Band1', 'Nadir_Reflectance_Band2', 'Nadir_Reflectance_Band4',
    'Nadir_Reflectance_Band3', 'Nadir_Reflectance_Band5',
    'Nadir_Reflectance_Band6', 'Nadir_Reflectance_Band7'];
var classProperty = 'Class';

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

print("classification done");


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

Export.image.toDrive({
    image: classified,
    description: 'LULC-modis',
    maxPixels: 1e13,
    region: ROI,
    scale: 30
});