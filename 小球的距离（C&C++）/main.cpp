#include <stdio.h>
#include <math.h>

/*
	��Ŀ����
	С������������һ����¥����С������վ��¥���Ĳ�ͬ�㣬����С��վ��¥���
	�����N�ף�����������������£�ÿ����غ������ϴ�����߶ȵ�һ�룬����
	������֪��ȫ���䵽���治������4��С��һ�������˶����ף�(���ֶ�Ϊ����)
	
	�����ĸ�����A,B,C,D���뷵����������
*/ 

double onceDistance(int cur){
	double i, dist = 0, doucur;
	//����ֵͬ��ת��Ϊ������ 
	doucur = cur;
	//ÿ������Ϊ֮ǰ��һ�� 
	for(i = (doucur / 2); i > 0; i = (i / 2)){
		//ÿ�ζ��������½������׶� 
		dist += (2 * i);
	}
	//���ϵ�һ�ν�����ľ��� 
	dist += doucur;
	return dist; 
} 

int calcDistance(int A, int B, int C, int D) {
	// write code here
	double dist = 0;
	//���μ����ĸ��˵ľ���
	dist += onceDistance(A);
	dist += onceDistance(B);
	dist += onceDistance(C);
	dist += onceDistance(D);
	return ceil(dist);
}

int main(int argc, char** argv) {
	int A, B, C, D, dist;
	while(scanf("%d %d %d %d", &A, &B, &C, &D) != EOF){
		dist = calcDistance(A, B, C, D);
		printf("%d\n", dist);
	}
}
