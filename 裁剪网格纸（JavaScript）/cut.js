/*
题目描述
度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的
话，每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把
这个正方形剪下来。问剪掉正方形的最小面积是多少。 

输入描述:
第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi,yi(－1e9<=xi,yi<=1e9)表示网格上的点

输出描述:
一行输出最小面积
*/

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input = "";
var input_array = "";

//读取输入数据
process.stdin.on('data',function(data){
    input += data;
});

//当进程将要退出时触发
process.stdin.on('end',function(){
    //根据回车键分割input数据为数组
    input_array = input.split('\n');
    //记录此时遍历的行下标
    var line = 0;
    //遍历所有输入条件（JS中系统同时输入多种测试条件，因此分次输出结果）
    while(line < input_array.length){
        //根据空格分割
        var codeline = input_array[line++];
        //排除错误输入情况
        if(codeline === ''){
            continue;
        }
        var code = codeline.trim().split(' ');
        //第一个值为坐标个数
        var num = +code[0];
        //初始化最大最小值
        var xmin = 0;
        var xmax = 0;
        var ymin = 0;
        var ymax = 0;
        //定义计数值
        var count = 0
        while(count < num){
            //根据空格分隔得到xy坐标
            var curline = input_array[line++]
            if(line === ''){
                continue;
            }
            var x_y = curline.trim().split(' ');
            var x = +x_y[0];
            var y = +x_y[1];
            //此时为第一个点初始化xy最大最小值
            if(count == 0){
                xmin = x;
                ymin = y;
                xmax = x;
                ymax = y;
            }
            //若此时x比之前最小x还要小，记录
            if(x < xmin){
                xmin = x;
            }
            //若此时y比之前最小y还要小，记录
            if(y < ymin){
                ymin = y;
            }
            //若此时x比之前最大x还要大，记录
            if(x > xmax){
                xmax = x;
            }
            //若此时y比之前最大y还要大，记录
            if(y > ymax){
                ymax = y;
            }
            count++;
        }
        //计算所有点x坐标与y坐标的最大差距
        var xlen = xmax - xmin;
        var ylen = ymax - ymin;
        //计算正方形面积
        var maxvalue = Math.max(xlen,ylen);
        var area = maxvalue * maxvalue;
        console.log(area);
    }
});