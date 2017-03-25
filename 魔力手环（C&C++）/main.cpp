#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int *num, i, j, fir;
		num = (int*)malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		for(i = 0; i < k; i++){
			//记录第一个数
			fir = num[0]; 
			//变换数字一次 
			for(j = 0; j < n - 1; j++){
				num[j] = num[j] + num[j + 1];
				//大于100对100取模 
				if(num[j] >= 100){
					num[j] = num[j] % 100;
				}
			}
			num[n - 1] = num[n - 1] + fir;
			if(num[n - 1] >= 100){
				num[n - 1] = num[n - 1] % 100;
			}
		}
		for(i = 0; i < n - 1; i++){
			printf("%d ", num[i]);
		}
		printf("%d\n", num[n - 1]);
	}
}
