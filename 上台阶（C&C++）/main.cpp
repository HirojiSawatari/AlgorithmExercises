#include <stdio.h>
 
/*
	��Ŀ����
	��һ¥�ݹ�m�����տ�ʼʱ���ڵ�һ������ÿ��ֻ�ܿ���һ�����߶�����Ҫ����
	m�������ж����߷���ע���涨��һ����һ����0���߷���
	����һ��������int n���뷵��һ������������¥�ķ�ʽ������֤nС�ڵ���100��
	Ϊ�˷�ֹ������뷵�ؽ��Mod 1000000007��ֵ��
*/
 
int countWays(int n) {
	// write code here
	//�õݹ�ᳬʱ��ֻ���ö�̬�滮 
	int i, way[n]; 
	//��ǰ�������������� 
	if(n == 0){
		return 0;
	} 
 	else if(n == 1){
 		return 1;
 	}
 	else if(n == 2){
 		return 2;
 	}
 	else{
 		way[1] = 1;
 		way[2] = 2;
 		for(i = 3; i < n; i++){
 			//��Ϊ���Կ�һ����������������ڿ����һ��֮ǰ�������������Ӽ��� 
 			way[i] = (way[i - 1] + way[i - 2]) % 1000000007;
 		}
 	} 
 	return way[i - 1];
}

int main(int argc, char** argv) {
	int n, way;
	while(scanf("%d", &n) != EOF){
		way = countWays(n);
		printf("%d\n", way);
	}
}
