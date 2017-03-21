#include <stdio.h>

/*
	题目描述
	对于一个由0..n的所有数按升序组成的序列，我们要进行一些筛选，每次我们取当前所有数
	字中从小到大的第奇数位个的数，并将其丢弃。重复这一过程直到最后剩下一个数。请求出
	最后剩下的数字。
	
	输入描述:
	每组数据一行一个数字，为题目中的n(n小于等于1000)。
	
	输出描述:
	一行输出最后剩下的数字。
*/

int thrownum(int num[], int n){
	int i, j, fin, newnum[n];
	//元素个数大于1，进行丢弃操作 
	if(n > 1){
		//计数值 
		j = 0; 
		//从第二个开始遍历，每隔一个元素遍历一次 
		for(i = 1; i < n; i = i + 2){
			newnum[j] = num[i];
			j++;
		}
		fin = thrownum(newnum, j);
		return fin;
	}
	//只剩一个了，返回第一个值 
	else{
		return num[0];
	} 
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		int i, fin, num[n + 1];
		//初始化数组 
		for(i = 0; i < n + 1; i++){
			num[i] = i; 
		}
		//递归函数（当前数组，当前数组元素个数） 
		fin = thrownum(num, n + 1);
		printf("%d\n", fin); 
	}
}
