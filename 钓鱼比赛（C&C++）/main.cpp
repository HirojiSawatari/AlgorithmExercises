#include <stdio.h>
#include <math.h>

/*
	题目描述
	ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，cc一直在
	坐标(x,y)的格子钓鱼，而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的
	概率大？为多少？
	
	输入描述:
	第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
	接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格
	子钓到鱼的概率为p(0≤p≤1)
	
	输出描述:
	输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)
*/

int main() {
	int i, j, n, m, x, y, t;
	while(scanf("%d %d %d %d %d", &n, &m, &x, &y, &t) != EOF){
		double p[n][m];
		//输入时按照行扫描
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				scanf("%lf", &p[i][j]);
			}
		}
		//矩阵上为钓到鱼的概率，1减其即为钓不到鱼的概率 (注意，xy表示第几行第几列，并不是坐标)
		double cc = 1 - p[x - 1][y - 1];
		//求cc在t分钟后至少一条鱼的概率 
		cc = 1- pow(cc, t);
		//因为随机，所以ss每一分钟选择任意网格的概率相同，因此每分钟的概率为所有概率平均值
		double ss = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				//钓到鱼的概率
				ss += p[i][j];
			}
		} 
		//每个网格钓到鱼的概率平均值 
		ss /= (n * m);
		//t分钟后至少一条鱼的概率（钓不到鱼的相反事件） 
		ss = 1 - pow(1 - ss, t);
		//判断 
		if(ss == cc){
			printf("equal\n%.2f\n", ss);
		} 
		else if(ss > cc){
			printf("ss\n%.2lf\n", ss);
		}
		else{
			printf("cc\n%.2lf\n", cc);
		} 
	}
}
