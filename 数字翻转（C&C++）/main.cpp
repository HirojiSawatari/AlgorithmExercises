#include <stdio.h>
#include <math.h>

/*
	对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
	如果 X = 123，则rev(X) = 321;
	如果 X = 100，则rev(X) = 1.
	现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？
	 
	输入描述:
	输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。
	
	输出描述:
	输出rev(rev(x) + rev(y))的值
*/

int rev(int num){
	//最多四位数 
	int n[4], i, len, newnum = 0;
	//计算该数的位数 
	for(len = 0; len < 4; len++){
		if(num / pow(10, len) < 1){
			break; 
		}
	} 
	//2为百位，1为十位，0为个位 
	for(i = len - 1; i > -1; i--){
		//得到该位数字 
		n[i] = num / (pow(10, i));
		//余数为去掉该位数字后剩下的数字 
		num = num % (int)(pow(10, i));
	}
	//转换 
	for(i = 0; i < len; i++){
		newnum += n[i] * pow(10, len - 1 - i);
	}
	return newnum;
}

int main() {
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		int nx, ny, f;
		nx = rev(x);
		ny = rev(y);
		f = rev(nx + ny);
		printf("%d\n", f);
	}
}
