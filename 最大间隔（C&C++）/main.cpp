#include <stdio.h>
#include <stdlib.h>

/*
	题目描述
	给定一个递增序列，a1 <a2 <...<an 。定义这个序列的最大间隔为d=max{ai+1 - ai }(1≤i<n),现在
	要从a2 ,a3 ..an-1 中删除一个元素。问剩余序列的最大间隔最小是多少？
	
	输入描述:
	第一行，一个正整数n(1<=n<=100),序列长度;接下来n个小于1000的正整数，表示一个递增序列。
	
	输出描述:
	输出答案。
*/ 

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		int *a, *ad, i, j, min = 1000, curmax;
		//动态分配空间，此后停止使用a[n]，尽管C99允许 
		a = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		//间隔数组，ad[n]表示n和n+1间距离 
		ad = (int*)malloc(sizeof(int) * (n - 1));
		for(i = 0; i < n - 1; i++){
			ad[i] = a[i + 1] - a[i];
		} 
		//遍历删除 
		for(i = 0; i < n - 2; i++){
			//删除点左右间隔合并 
			curmax = ad[i] + ad[i + 1];
			//求当前最大间隔 
			for(j = 0; j < n - 1; j++){
				if(ad[j] > curmax){
					curmax = ad[j];
				}
			} 
			//求最小的最大间隔 
			if(min > curmax){
				min = curmax;
			}
		} 
		printf("%d\n", min);
	}
}
