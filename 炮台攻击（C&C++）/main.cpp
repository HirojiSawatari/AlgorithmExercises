#include <stdio.h>
#include <math.h>

/*
	��Ŀ����
	������ѵ��Ī֮��,Ȼ�����Ī������Լ�¶���,̸��Լ�¶���,��Ȼ�ٲ���һ����,�� ���Ǻ�Ĭ��
	��------Լ�¶�����ʷ����ΰ��Ŀ�ѧ��. ��Ī˵,��Ĭ���������˼��һ������:��Ĭ����������
	��̨,��̨�ܹ�����������R�ĵ��� (����֮��ľ���Ϊ���������ľ���,����(3,0),(0,4)֮��ľ�
	����5),���һ����̨�ܹ��� ������,��ô�ͻ�Ե������1�����˺�.��Ĭ����������̨����N*M��
	���еĵ���,���Ҹ������� ������. ��:��ô�����ܵ��˺����Ƕ��?
	
	��������:
	��һ��9������,R,x1,y1,x2,y2,x3,y3,x0,y0.R������̨������������,(x1,y1),(x2,y2),
	(x3,y3)����������̨������.(x0,y0)������˵�����.
	
	�������:
	���һ��,��һ�д�����˳��ܵ�����˺�,(���ÿ����̨�����ܹ���������,���0��)
*/

int injury(int R, int x, int y, int x0, int y0){
	int a, b, inj = 0;
	float dist;
	//������������˼�ľ��� 
	a = fabs(x0 - x);
	b = fabs(y0 - y);
	dist = sqrt(pow(a, 2) + pow(b, 2));
	//������С�ڵ�����̣����ܵ��˺� 
	if(dist <= R){
		inj++; 
	}
	return inj; 
}

int shoot(int R, int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0){
	int totalinj = 0;
	totalinj += injury(R, x1, y1, x0, y0);
	totalinj += injury(R, x2, y2, x0, y0);
	totalinj += injury(R, x3, y3, x0, y0);
	printf("%dx\n", totalinj);
	return 0;
}

int main(){
	int R, x1, y1, x2, y2, x3, y3, x0, y0;
	while(scanf("%d %d %d %d %d %d %d %d %d", &R, &x1, &y1, &x2, &y2, &x3, &y3, &x0, &y0)!=EOF){
		shoot(R, x1, y1, x2, y2, x3, y3, x0, y0);
	}
}
