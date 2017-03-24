#include <stdio.h>
#include <math.h> 

/*
	题目描述
	现在有一张半径为r的圆桌，其中心位于(x,y)，现在他想把圆桌的中心移到(x1,y1)。每次移
	动一步，都必须在圆桌边缘固定一个点然后将圆桌绕这个点旋转。问最少需要移动几步。
	
	输入描述:
	一行五个整数r,x,y,x1,y1(1≤r≤100000,-100000≤x,y,x1,y1≤100000)
	
	输出描述:
	输出一个整数，表示答案
*/
 
int main() {
	double r, x, y, x1, y1;
	while(scanf("%lf %lf %lf %lf %lf",&r, &x, &y, &x1, &y1) != EOF){
		double dis; 
		//求出新老中心点的直线距离 
		dis = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
		//旋转一次能移动的最大距离为2r
		int t;
		//进一法保留整数 
		t = ceil(dis / (2 * r));
		printf("%d\n", t);
	}
}
