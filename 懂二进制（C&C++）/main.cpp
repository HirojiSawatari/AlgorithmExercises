#include <stdio.h>

/*
	��Ŀ����
	��������10���ˣ�һ�ֶ������ƣ�һ�ֲ�������ô��֪������in
	t32����m��n�Ķ����Ʊ��ж��ٸ�λ(bit)��ͬô�� 
*/


/**
 * ����������ζ����Ʊ��λ����ͬ������
 * 
 * @param m ����m
 * @param n ����n
 * @return ����
 */
int countBitDiff(int m, int n) {
	int mq, nq, sum = 0;
	//����ʱintΪ0����1 
	while(m > 0 || n > 0){
		mq = m % 2;
		nq = n % 2;
		//���ݶ�����ԭ���ж����� 
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
