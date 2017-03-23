#include <stdio.h>

/*
	小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函
	数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
	现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
	例如： N = 7 
	f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
	小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。 
	
	输入描述:
	输入一个整数N (1 ≤ N ≤ 1000000000)
	
	输出描述:
	输出一个整数，即为f(1) + f(2) + f(3).......f(N)
*/

//求最大奇约数，此方法直接计算时间复杂度大，废弃 
int f(int n){
	int i;
	for(i = n; i > 0; i--){
		//整除，约数 
		if(n % i == 0){
			//不能被2整除，奇数 
			if(i % 2 != 0){
				break;
			} 
		}
	}
	return i;
}

//n为奇数时，最大奇约数为其本身，且2n的最大奇约数为n，因此f(2) + f(4) + ... + f(2k) = f(1) + f(2) + ... + f(k)
long long fsum(long long N){ 
	if(N == 1){
		return 1;
	} 
	//偶数 sum(n) = sum (n / 2) + 1 + 3 + ... + n - 1 = sum (n/2) + n*n/4
	else if(N % 2 == 0){
		return fsum(N / 2) + (N * N / 4);
	}
	//奇数 sum(n) = sum (n - 1) + n
	else{
		return fsum(N - 1) + N;
	}
} 

int main() {
	long long N;
	while(scanf("%ld", &N) != EOF){
		long long total;
		total = fsum(N);
		printf("%ld\n", total);
	}
}
