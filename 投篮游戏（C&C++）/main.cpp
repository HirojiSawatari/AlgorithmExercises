#include <stdio.h>
#include <stdlib.h>

/*
	题目描述
	有一个投篮游戏。球场有p个篮筐，编号为0，1...，p-1。每个篮筐下有个
	袋子，每个袋子最多装一个篮球。有n个篮球，每个球编号xi 。规则是将数
	字为xi 的篮球投到xi 除p的余数为编号的袋里。若袋里已有篮球则球弹出
	游戏结束输出i，否则重复至所有球都投完。输出-1。问游戏最终的输出是
	什么？
	
	输入描述:
	第一行两个整数p,n（2≤p,n≤300)。p为篮筐数，n为篮球数。接着n行为篮
	球上的数字xi(0≤xi≤1e9)
	
	输出描述:
	输出游戏的结果
*/

int main() {
	//篮筐数p，篮球数n 
	int p, n;
	while(scanf("%d %d", &p, &n) != EOF){
		int *x, i, *b, code;
		x = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &x[i]);
		}
		//创建篮筐数组
		b = (int*)malloc(sizeof(int) * p);
		for(i = 0; i < p; i++){
			b[i] = 0;
		}
		//模拟投球 
		for(i = 0; i < n; i++){
			code = x[i] % p;
			b[code]++;
			//此篮筐满，弹出 
			if(b[code] > 1){
				break;
			}
		} 
		//遍历完成，未弹出 
		if(i == n){
			printf("-1\n"); 
		} 
		else{
			printf("%d\n", i + 1);
		}
	}
}
