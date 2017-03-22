#include <stdio.h>
#include <math.h>

/*
	����һ������X���������rev(X)Ϊ��X����λ��ת����������ȥ����ǰ��0������:
	��� X = 123����rev(X) = 321;
	��� X = 100����rev(X) = 1.
	���ڸ�������x��y,Ҫ��rev(rev(x) + rev(y))Ϊ���٣�
	 
	��������:
	����Ϊһ�У�x��y(1 �� x��y �� 1000)���Կո������
	
	�������:
	���rev(rev(x) + rev(y))��ֵ
*/

int rev(int num){
	//�����λ�� 
	int n[4], i, len, newnum = 0;
	//���������λ�� 
	for(len = 0; len < 4; len++){
		if(num / pow(10, len) < 1){
			break; 
		}
	} 
	//2Ϊ��λ��1Ϊʮλ��0Ϊ��λ 
	for(i = len - 1; i > -1; i--){
		//�õ���λ���� 
		n[i] = num / (pow(10, i));
		//����Ϊȥ����λ���ֺ�ʣ�µ����� 
		num = num % (int)(pow(10, i));
	}
	//ת�� 
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
