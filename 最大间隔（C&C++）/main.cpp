#include <stdio.h>
#include <stdlib.h>

/*
	��Ŀ����
	����һ���������У�a1 <a2 <...<an ������������е������Ϊd=max{ai+1 - ai }(1��i<n),����
	Ҫ��a2 ,a3 ..an-1 ��ɾ��һ��Ԫ�ء���ʣ�����е��������С�Ƕ��٣�
	
	��������:
	��һ�У�һ��������n(1<=n<=100),���г���;������n��С��1000������������ʾһ���������С�
	
	�������:
	����𰸡�
*/ 

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		int *a, *ad, i, j, min = 1000, curmax;
		//��̬����ռ䣬�˺�ֹͣʹ��a[n]������C99���� 
		a = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		//������飬ad[n]��ʾn��n+1����� 
		ad = (int*)malloc(sizeof(int) * (n - 1));
		for(i = 0; i < n - 1; i++){
			ad[i] = a[i + 1] - a[i];
		} 
		//����ɾ�� 
		for(i = 0; i < n - 2; i++){
			//ɾ�������Ҽ���ϲ� 
			curmax = ad[i] + ad[i + 1];
			//��ǰ����� 
			for(j = 0; j < n - 1; j++){
				if(ad[j] > curmax){
					curmax = ad[j];
				}
			} 
			//����С������� 
			if(min > curmax){
				min = curmax;
			}
		} 
		printf("%d\n", min);
	}
}
