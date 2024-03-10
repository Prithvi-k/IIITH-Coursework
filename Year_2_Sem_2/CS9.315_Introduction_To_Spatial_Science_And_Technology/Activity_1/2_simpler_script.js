var selection = L9.filterBounds(ROI)
    .filterDate('2022-01-01', '2024-01-01')
    .filterMetadata('CLOUD_COVER', 'less_than', 1)
    .median()
    .clip(ROI);

print(selection);

Map.addLayer(selection, { bands: ["B4", "B3", "B2"] });

var training_points = builtup.merge(arid).merge(vegetation).merge(water);

var training_data = selection.sampleRegions({
    collection: training_points,
    properties: ['LC'],
    scale: 30
});

print(training_data); // Might lead to less number of points than selected
// because some bands may not have data for some points

var classifier = ee.Classifier.cart().train({
    features: training_data,
    classProperty: 'LC',
    inputProperties: ['B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8']
});

var classified_image = selection.classify(classifier);

Map.addLayer(classified_image, { min: 0, max: 3, palette: ['0049bf', '07c46f', 'ddd60b', 'c91700'] }, 'classified_image');

print(classifier.confusionMatrix());