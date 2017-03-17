#include <stdio.h>

/*
	题目描述
	世界上有10种人，一种懂二进制，一种不懂。那么你知道两个in
	t32整数m和n的二进制表达，有多少个位(bit)不同么？ 
*/


/**
 * 获得两个整形二进制表达位数不同的数量
 * 
 * @param m 整数m
 * @param n 整数n
 * @return 整型
 */
int countBitDiff(int m, int n) {
	int mq, nq, sum = 0;
	//除尽时int为0不是1 
	while(m > 0 || n > 0){
		mq = m % 2;
		nq = n % 2;
		//根据二进制原理判断余数 
		if(mq != nq){
			sum++;
		}
		m /= 2;
		n /= 2;
	}
	return sum;
}

int main(int argc, char** argv) {
	int m, n, sum;
	while(scanf("%d %d", &m, &n) != EOF){
		sum = countBitDiff(m, n);
		printf("%d\n", sum);
	}
}
