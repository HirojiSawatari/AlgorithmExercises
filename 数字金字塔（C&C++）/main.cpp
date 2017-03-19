#include <stdio.h>

/*
	考虑在下面被显示的数字金字塔。 写一个程序来计算从最高点开始在底部任意处结束的
	路径经过数字的和的最大。 每一步可以走到左下方的点也可以到达右下方的点。
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5
	在上面的样例中,从7 到 3 到 8 到 7 到 5 的路径产生了最大和:30
	
	输入格式：
	第一个行包含 R(1<= R<=1000) ,表示行的数目。后面每行为这个数字金字塔特定行包
	含的整数。所有的被供应的整数是非负的且不大于100。
	
	输出格式：
	单独的一行包含那个可能得到的最大的和。
*/

//递归求最大（以一维数组形式传入不定长二维数组） 
int gostep(int R, int *py, int step, int x, int y){
	int maxstep, step1, step2; 
	//记录当前数字 
	step += py[x * (R * 2 - 1) + y];
	//越界，返回当前步数 
	if(x + 1 == R){
		return step;
	}
	//不越界即可向左右两侧继续返回较大值 
	else{
		step1 = gostep(R, py, step, x + 1, y + 1); 
		step2 = gostep(R, py, step, x + 1, y - 1);
		maxstep = (step1 > step2) ? step1 : step2;
		return maxstep; 
	} 
}

int main(int argc, char** argv) {
	int R, i, j;
	while(scanf("%d", &R) != EOF){
		int py[R][(R * 2 - 1)];
		//构建金字塔 
		for(i = 0; i < R; i++){
			for(j = (R - i - 1); j < (R + i) ; j= j + 2){
				scanf("%d", &py[i][j]);
			}
		}
		//从最高点开始向下遍历 
		int maxstep = gostep(R, *py, 0, 0, R - 1);
		printf("%d\n", maxstep);
	}
}
