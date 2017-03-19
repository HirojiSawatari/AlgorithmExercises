#include <stdio.h>

/*
	���������汻��ʾ�����ֽ������� дһ���������������ߵ㿪ʼ�ڵײ����⴦������
	·���������ֵĺ͵���� ÿһ�������ߵ����·��ĵ�Ҳ���Ե������·��ĵ㡣
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5
	�������������,��7 �� 3 �� 8 �� 7 �� 5 ��·������������:30
	
	�����ʽ��
	��һ���а��� R(1<= R<=1000) ,��ʾ�е���Ŀ������ÿ��Ϊ������ֽ������ض��а�
	�������������еı���Ӧ�������ǷǸ����Ҳ�����100��
	
	�����ʽ��
	������һ�а����Ǹ����ܵõ������ĺ͡�
*/

//�ݹ��������һά������ʽ���벻������ά���飩 
int gostep(int R, int *py, int step, int x, int y){
	int maxstep, step1, step2; 
	//��¼��ǰ���� 
	step += py[x * (R * 2 - 1) + y];
	//Խ�磬���ص�ǰ���� 
	if(x + 1 == R){
		return step;
	}
	//��Խ�缴������������������ؽϴ�ֵ 
	else{
		step1 = gostep(R, py, step, x + 1, y + 1); 
		step2 = gostep(R, py, step, x + 1, y - 1);
		maxstep = (step1 > step2) ? step1 : step2;
		return maxstep; 
	} 
}

int main(int argc, char** argv) {
	int R, i, j;
	while(scanf("%d", &R) != EOF){
		int py[R][(R * 2 - 1)];
		//���������� 
		for(i = 0; i < R; i++){
			for(j = (R - i - 1); j < (R + i) ; j= j + 2){
				scanf("%d", &py[i][j]);
			}
		}
		//����ߵ㿪ʼ���±��� 
		int maxstep = gostep(R, *py, 0, 0, R - 1);
		printf("%d\n", maxstep);
	}
}
