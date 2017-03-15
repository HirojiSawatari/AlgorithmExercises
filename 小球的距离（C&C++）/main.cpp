#include <stdio.h>
#include <math.h>

/*
	题目描述
	小东和三个朋友一起在楼上抛小球，他们站在楼房的不同层，假设小东站的楼层距
	离地面N米，球从他手里自由落下，每次落地后反跳回上次下落高度的一半，并以
	此类推知道全部落到地面不跳，求4个小球一共经过了多少米？(数字都为整数)
	
	给定四个整数A,B,C,D，请返回所求结果。
*/ 

double onceDistance(int cur){
	double i, dist = 0, doucur;
	//输入值同样转换为浮点型 
	doucur = cur;
	//每次上升为之前的一半 
	for(i = (doucur / 2); i > 0; i = (i / 2)){
		//每次都有上升下降两个阶段 
		dist += (2 * i);
	}
	//加上第一次仅下落的距离 
	dist += doucur;
	return dist; 
} 

int calcDistance(int A, int B, int C, int D) {
	// write code here
	double dist = 0;
	//依次计算四个人的距离
	dist += onceDistance(A);
	dist += onceDistance(B);
	dist += onceDistance(C);
	dist += onceDistance(D);
	return ceil(dist);
}

int main(int argc, char** argv) {
	int A, B, C, D, dist;
	while(scanf("%d %d %d %d", &A, &B, &C, &D) != EOF){
		dist = calcDistance(A, B, C, D);
		printf("%d\n", dist);
	}
}
