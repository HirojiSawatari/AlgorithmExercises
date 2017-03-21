#include <stdio.h>

/*
	题目描述
	老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位
	同学的成绩. 
	
	输入描述:
	输入包括多组测试数据。
	每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
	学生ID编号从1编到N。
	第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
	接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问
	操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
	当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
	
	输出描述:
	对于每一次询问操作，在一行里面输出最高成绩.
*/

int main() {
	//学生数和执行操作数 
	int N, M;
	while(scanf("%d %d", &N, &M) != EOF){
		int i, j, maxg, temp, grade[N], A[M], B[M];
		char shell[M];
		//输入学生成绩 
		for(i = 0; i < N; i++){
			scanf("%d%*c", &grade[i]); 
		}
		//输入指令
		for(i = 0; i < M; i++){
			//注意：用%*c吸收回车符防止下一行读入 
			scanf("%c %d %d%*c", &shell[i], &A[i], &B[i]); 
		}
		//遍历指令
		for(i = 0; i < M; i++){
			//判断指令类型 
			if(shell[i] == 'Q'){
				if(A[i] > B[i]){	//写反了，调整 
					temp = A[i];
					A[i] = B[i];
					B[i] = temp; 
				} 
				//输出成绩最高学生
				maxg = grade[A[i] - 1];
				for(j = A[i]; j < B[i]; j++){
					if(maxg < grade[j]){
						maxg = grade[j];
					}
				}
				printf("%d\n", maxg); 
			}
			else if(shell[i] == 'U'){
				//改成绩
				grade[A[i] - 1] = B[i]; 
			}
		} 
	} 
}
