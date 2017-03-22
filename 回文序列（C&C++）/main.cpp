#include <stdio.h>

/*
	如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
	{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
	{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
	现在给出一个数字序列，允许使用一种转换操作：
	选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之
	前的位置(只插入一个和)。
	现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。
	
	输入描述:
	输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
	第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。
	
	输出描述:
	输出一个数，表示最少需要的转换次数
*/

//原数组，操作次数，头下标，尾下标 
int palindrome(int *code, int t, int head, int tail){
	int i, j;
	//遍历数组判断回文 
	while(head < tail && code[head] != code[tail]){
		//发现不相等的值，将较小值与之后的值相加 
		if(code[head] < code[tail]){
			code[head + 1] = code[head] + code[head + 1];
			head++;
			t++;
		} 
		else{
			code[tail - 1] = code[tail] + code[tail - 1];
			tail--;
			t++;
		}
	}
	//遍历结束返回值 
	if(head >= tail){
		return t;
	}
	//当前两点已形成回文，继续下一个点开始遍历 
	else{
		return palindrome(code, t, ++head, --tail);
	}
}

int main() {
	int n, i, t;
	while(scanf("%d", &n) != EOF){
		int code[n];
		for(i = 0; i < n; i++){
			scanf("%d", &code[i]);
		}
		t = palindrome(code, 0, 0, n - 1);
		printf("%d\n", t);
	}
}
