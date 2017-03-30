#include <stdio.h>
#include <stdlib.h>

/*
	题目描述：
	按数组的形式给出函数f(x)的取值，即数组A的A[0]元素为f(0)的取值，数组的取值都为整数，函
	数在每个点都是严格单调递增或者严格递减（即A[i-1] != A[i] != A[i+1]），要求找出最宽的先
	上升后下降的区间（这个区间内函数的值必须先上升到一个点然后下降，区间的上升段和下降段长
	度必须都大于0）。
	1. 如果找到符合条件的最大区间输出数组对应的左右下标（有多个最大区间时，输出最左边的那个”）
	2. 找不到那么输出-1 -1
	
	输入
	n
	n长度的整数数组
	
	输出
	区间的范围
*/

int main() { 
	//isup=0为不符合条件，1为上升时，2为下降时 
	int n, isup = 0, count = 0, maxcount = 0, left, ml = -1, mr = -1;
	while(scanf("%d", &n) != EOF){
		int *A, i;
		A = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		if(n > 1){
			//初始化趋势（记录先上升后下降） 
			if(A[1] - A[0] > 0){
				//上升
				 isup = 1;
				 count = 1;
				 left = 0; 
			}
			//从第二个开始 
			for(i = 2; i < n; i++){
				//跳出一段区间 
				if(A[i] - A[i - 1] > 0 && (isup == 2 || isup == 0)){
					if(count > maxcount){
						maxcount = count;
						ml = left;
						mr = i - 1;
					}
					isup = 1;
					count = 1;
					left = i - 1; 
				}
				//区间内上升阶段 
				else if(A[i] - A[i - 1] > 0 && isup == 1){
					count++;
				} 
				//开始下降阶段 
				else if(A[i] - A[i - 1] < 0 && isup == 1){
					isup = 2;
					count++; 
				}
				else{
					isup = 0;
				}
			}
			//判断结尾
			if(count > maxcount && isup == 2){
				maxcount = count;
				ml = left;
				mr = i - 1;
			}
		}
		printf("%d %d\n", ml, mr);
	}
}
