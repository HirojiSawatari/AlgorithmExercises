#include <stdio.h>

//�ַ�������ǰ�±꣬�ַ������ȣ���ǰ���������ĳ��ȣ���ǰ��������������ַ�����󳤶� 
int calc(int *code, int x, int n, int total, int mincode, int maxt){
	int i, curt, curmax = maxt;
	if(x == n - 1){
		if(maxt < total){
			return total;
		}
		else{
			return maxt;
		}
	}
	else{
		for(i = (x + 1); i < n; i++){
			if(code[i] > mincode){
				mincode = code[i];
				total++;
			}
			curt = calc(code, i, n, total, mincode, maxt);
			if(curt > curmax){
				curmax = curt;
			}
		}
		return curmax;
	}
}

int main() {
	int i, j, total, calt, mincode, n, maxt = 0;
	//�������ɳ���
	scanf("%d", &n);
	int code[n];
	for(i = 0; i < n; i++){
		scanf("%d", &code[i]);
	} 
	//�ֱ��Ը�����Ϊ��һ������
	for(i = 0; i < n; i++){
		calt = calc(code, i, n, 1, code[i], 0);
		if(calt > maxt){
			maxt = calt;
		}
	} 
	printf("%d", maxt);
}
