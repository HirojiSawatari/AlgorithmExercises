#include <stdio.h>
#include <stdlib.h>

/*
	��Ŀ����
	A��B�Ǻ��ѣ����Ǿ����ڿ���ʱ�����죬A�Ŀ���ʱ��Ϊ[a1 ,b1 ],[a2 ,b2 ]..[ap ,bp ]��B��
	����ʱ����[c1 +t,d1 +t]..[cq +t,dq +t],����tΪB����ʱ�䡣��Щʱ������˱߽�㡣B��
	��ʱ��Ϊ[l,r]��һ��ʱ�̡���һ����ʱ����ʹ����������ʱ�����죬��ô���ʱ����Ǻ���
	�ģ����ж��ٸ����ʵ���ʱ�䣿
	
	��������:
	��һ�������ĸ�������p,q,l,r��1��p,q��50,0��l��r��1000)��������p������ÿһ����һ������
	ai��bi(0��aii+1>bi,ci+1>di
	
	�������:
	����𰸸���
*/

int main() {
	//a�Ŀռ�ʱ�����p��b�Ŀ���ʱ�����q��b����ʱ���l��r 
	int p, q, l, r;
	while(scanf("%d %d %d %d", &p, &q, &l, &r) != EOF){
		int i, j, k, *a, *b, *c, *d, total = 0, istrue;
		a = (int*)malloc(sizeof(int) * p);
		b = (int*)malloc(sizeof(int) * p);
		c = (int*)malloc(sizeof(int) * q); 
		d = (int*)malloc(sizeof(int) * q);  
		for(i = 0; i < p; i++){
			scanf("%d %d", &a[i], &b[i]);
		}
		for(i = 0; i < q; i++){
			scanf("%d %d", &c[i], &d[i]);
		}
		//������ʱ�� 
		for(i = l;i <= r; i++){
			//��Ǵ���ʱ���Ƿ�����Ҫ�� 
			istrue = 0;
			//����b�Ŀ���ʱ��� 
			for(j = 0; j < q; j++){
				//����a�Ŀ���ʱ���
				 for(k = 0; k < p; k++){
				 	//�ж�ʱ����Ƿ��غ� 
				 	if((((c[j] + i) <= a[k]) && ((d[j] + i) >= a[k])) || (((c[j] + i) <= b[k]) && ((d[j] + i) >= b[k]))){
				 		//�������죬����k����
				 		istrue = 1; 
						total++;
						break; 
				 	}
				 }
				 //�ж��Ƿ����j����
				 if(istrue == 1){
				 	break;
				 } 
			}
		}
		printf("%d\n", total);
	} 
}
