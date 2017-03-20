import java.util.*;

/*
 *题目描述
 *现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。现在A想要拜访B，由于她只
 *想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),
 *问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
 *
 *输入描述:
 *第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有
 *一个蘑菇。
 *
 *输出描述:
 *输出一行，代表所求概率(保留到2位小数) 
 */

public class Mushroom {
	public static void calMush(int[][] mushroom, int[] x, int[] y, int K){
		//将有蘑菇的点值记为1
		for(int i = 0; i < K; i++){
			mushroom[x[i] - 1][y[i] - 1] = 1;
		}
	}
	
	//原方法：路径数/总路径数，因为走不同路径的概率是不相等的，例如边界，因此此方法求得的结果是错误的
	//遍历（矩阵，终点xy，当前点xy，总线路数和符合条件线路数，当前线路是否有蘑菇）
	public static int[] step(int[][] mushroom, int N, int M, int x, int y, int[] count, boolean isnomush){
		//判断当前点是否有蘑菇
		if(mushroom[x][y] == 1){
			isnomush = false;
		}
		//到达终点
		if(x == N && y == M){
			//总线路加一
			count[0]++;
			//路上未碰到蘑菇，符合条件线路加一
			if(isnomush == true){
				count[1]++;
			}
		}
		else{
			int[] count1 = new int[2];
			int[] count2 = new int[2];
			//未溢出执行递归
			if(x + 1 < N + 1){
				count1 = step(mushroom, N, M, x + 1, y, count, isnomush);
			}
			if(y + 1 < M + 1){
				count2 = step(mushroom, N, M, x, y + 1, count, isnomush);
			}
			count[0] = count1[0] + count2[0];
			count[1] = count1[1] + count2[1];
		}
		return count;
	}
	
	//求到达各点的概率
	public static double getProb(int[][] mushroom, double[][] p, int N, int M){
		//起点概率为1
		p[1][1] = 1;
		for(int i = 1; i < N + 1; i++){
			for(int j = 1; j < M + 1; j++){
				//排除起点
				if(!(i == 1 && j == 1)){
					//有蘑菇，该点几率为0
					if(mushroom[i - 1][j - 1] == 1){
						p[i][j] = 0;
					}
					//边界的时候，概率为1，否则到该点的几率为0.5
					else{
						p[i][j] = p[i - 1][j] * (j == M ? 1 : 0.5) + p[i][j - 1] * (i == N ? 1 : 0.5);
					}
				}
			}
		}
		//返回终点概率
		return p[N][M];
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextInt()){
			//输入草地大小N，M和蘑菇数K
			int N = input.nextInt();
			int M = input.nextInt();
			int K = input.nextInt();
			//输入蘑菇坐标
			int[] x = new int[K];
			int[] y = new int[K];
			for(int i = 0; i < K; i++){
				x[i] = input.nextInt();
				y[i] = input.nextInt();
			}
			//构建二维数组，初始化为0
			int[][] mushroom = new int[N][M];
			calMush(mushroom, x, y, K);
			/* 错误思路
			//计数值，count[0]为总线路数，count[1]为符合条件线路数
			int[] count = {0, 0};
			count = step(mushroom, N - 1, M - 1, 0, 0, count, true);
			float prob = (float)count[1] / (float)count[0];
			*/
			//初始化概率矩阵（留出值为0的边框）
			double[][] p = new double[N + 1][M + 1];
			double prob = getProb(mushroom, p, N, M);
			System.out.println(String.format("%.2f", prob));
		}
	}
}
