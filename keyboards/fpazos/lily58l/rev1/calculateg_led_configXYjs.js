var colsNum = 14;
var colMin = 1;

var rowNum = 5;
var rowMin = 1;

var reverse = false;

var string = '';

var colAdjustment = [8, 6, 2, 0, 2, 4, 0 , 0, 4, 2, 2, 0, 2, 6, 8];


var calculatePositions = function () {
    var x, y;
    for (var row = 0; row < rowNum; row++) {
        for (var col = 0; col < colsNum; col++) {

            x = Math.floor(224 / (colsNum - 1) * col);
            y = colAdjustment.length ? Math.floor(64 / (rowNum - 1) * row) + colAdjustment[col]: Math.floor(64 / (rowNum - 1) * row);

            string += '{' + x + ', ' + y + '},';
        }
        string += `
        `;
    }

}
calculatePositions();
console.log(string);
