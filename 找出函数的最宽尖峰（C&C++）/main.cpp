#include <stdio.h>
#include <stdlib.h>

/*
	��Ŀ������
	���������ʽ��������f(x)��ȡֵ��������A��A[0]Ԫ��Ϊf(0)��ȡֵ�������ȡֵ��Ϊ��������
	����ÿ���㶼���ϸ񵥵����������ϸ�ݼ�����A[i-1] != A[i] != A[i+1]����Ҫ���ҳ�������
	�������½������䣨��������ں�����ֵ������������һ����Ȼ���½�������������κ��½��γ�
	�ȱ��붼����0����
	1. ����ҵ��������������������������Ӧ�������±꣨�ж���������ʱ���������ߵ��Ǹ�����
	2. �Ҳ�����ô���-1 -1
	
	����
	n
	n���ȵ���������
	
	���
	����ķ�Χ
*/

int main() { 
	//isup=0Ϊ������������1Ϊ����ʱ��2Ϊ�½�ʱ 
	int n, isup = 0, count = 0, maxcount = 0, left, ml = -1, mr = -1;
	while(scanf("%d", &n) != EOF){
		int *A, i;
		A = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		if(n > 1){
			//��ʼ�����ƣ���¼���������½��� 
			if(A[1] - A[0] > 0){
				//����
				 isup = 1;
				 count = 1;
				 left = 0; 
			}
			//�ӵڶ�����ʼ 
			for(i = 2; i < n; i++){
				//����һ������ 
				if(A[i] - A[i - 1] > 0 && (isup == 2 || isup == 0)){
					if(count > maxcount){
						maxcount = count;
						ml = left;
						mr = i - 1;
					}
					isup = 1;
					count = 1;
					left = i - 1; 
				}
				//�����������׶� 
				else if(A[i] - A[i - 1] > 0 && isup == 1){
					count++;
				} 
				//��ʼ�½��׶� 
				else if(A[i] - A[i - 1] < 0 && isup == 1){
					isup = 2;
					count++; 
				}
				else{
					isup = 0;
				}
			}
			//�жϽ�β
			if(count > maxcount && isup == 2){
				maxcount = count;
				ml = left;
				mr = i - 1;
			}
		}
		printf("%d %d\n", ml, mr);
	}
}
