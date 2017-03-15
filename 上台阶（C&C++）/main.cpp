#include <stdio.h>
 
/*
	题目描述
	有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上
	m级，共有多少走法？注：规定从一级到一级有0种走法。
	给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。
	为了防止溢出，请返回结果Mod 1000000007的值。
*/
 
int countWays(int n) {
	// write code here
	//用递归会超时，只能用动态规划 
	int i, way[n]; 
	//提前输出三种特殊情况 
	if(n == 0){
		return 0;
	} 
 	else if(n == 1){
 		return 1;
 	}
 	else if(n == 2){
 		return 2;
 	}
 	else{
 		way[1] = 1;
 		way[2] = 2;
 		for(i = 3; i < n; i++){
 			//因为可以跨一步或者两步，因此在跨最后一步之前有两种情况，相加即可 
 			way[i] = (way[i - 1] + way[i - 2]) % 1000000007;
 		}
 	} 
 	return way[i - 1];
}

int main(int argc, char** argv) {
	int n, way;
	while(scanf("%d", &n) != EOF){
		way = countWays(n);
		printf("%d\n", way);
	}
}
