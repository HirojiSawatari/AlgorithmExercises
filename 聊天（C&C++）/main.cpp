#include <stdio.h>
#include <stdlib.h>

/*
	题目描述
	A和B是好友，他们经常在空闲时间聊天，A的空闲时间为[a1 ,b1 ],[a2 ,b2 ]..[ap ,bp ]。B的
	空闲时间是[c1 +t,d1 +t]..[cq +t,dq +t],这里t为B的起床时间。这些时间包括了边界点。B的
	起床时间为[l,r]的一个时刻。若一个起床时间能使两人在任意时刻聊天，那么这个时间就是合适
	的，问有多少个合适的起床时间？
	
	输入描述:
	第一行数据四个整数：p,q,l,r（1≤p,q≤50,0≤l≤r≤1000)。接下来p行数据每一行有一对整数
	ai，bi(0≤aii+1>bi,ci+1>di
	
	输出描述:
	输出答案个数
*/

int main() {
	//a的空间时间段数p，b的空闲时间段数q，b的起床时间段l，r 
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
		//遍历起床时间 
		for(i = l;i <= r; i++){
			//标记此起床时间是否满足要求 
			istrue = 0;
			//遍历b的空闲时间段 
			for(j = 0; j < q; j++){
				//遍历a的空闲时间段
				 for(k = 0; k < p; k++){
				 	//判断时间段是否重合 
				 	if((((c[j] + i) <= a[k]) && ((d[j] + i) >= a[k])) || (((c[j] + i) <= b[k]) && ((d[j] + i) >= b[k]))){
				 		//可以聊天，结束k遍历
				 		istrue = 1; 
						total++;
						break; 
				 	}
				 }
				 //判断是否结束j遍历
				 if(istrue == 1){
				 	break;
				 } 
			}
		}
		printf("%d\n", total);
	} 
}
