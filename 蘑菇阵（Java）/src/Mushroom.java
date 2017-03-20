import java.util.*;

/*
 *��Ŀ����
 *��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1,1),B��(n,m)������A��Ҫ�ݷ�B��������ֻ
 *��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),
 *�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
 *
 *��������:
 *��һ��N��M��K(1 �� N,M �� 20, k �� 100),N,MΪ�ݵش�С��������K�У�ÿ����������x��y������(x,y)����
 *һ��Ģ����
 *
 *�������:
 *���һ�У������������(������2λС��) 
 */

public class Mushroom {
	public static void calMush(int[][] mushroom, int[] x, int[] y, int K){
		//����Ģ���ĵ�ֵ��Ϊ1
		for(int i = 0; i < K; i++){
			mushroom[x[i] - 1][y[i] - 1] = 1;
		}
	}
	
	//ԭ������·����/��·��������Ϊ�߲�ͬ·���ĸ����ǲ���ȵģ�����߽磬��˴˷�����õĽ���Ǵ����
	//�����������յ�xy����ǰ��xy������·���ͷ���������·������ǰ��·�Ƿ���Ģ����
	public static int[] step(int[][] mushroom, int N, int M, int x, int y, int[] count, boolean isnomush){
		//�жϵ�ǰ���Ƿ���Ģ��
		if(mushroom[x][y] == 1){
			isnomush = false;
		}
		//�����յ�
		if(x == N && y == M){
			//����·��һ
			count[0]++;
			//·��δ����Ģ��������������·��һ
			if(isnomush == true){
				count[1]++;
			}
		}
		else{
			int[] count1 = new int[2];
			int[] count2 = new int[2];
			//δ���ִ�еݹ�
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
	
	//�󵽴����ĸ���
	public static double getProb(int[][] mushroom, double[][] p, int N, int M){
		//������Ϊ1
		p[1][1] = 1;
		for(int i = 1; i < N + 1; i++){
			for(int j = 1; j < M + 1; j++){
				//�ų����
				if(!(i == 1 && j == 1)){
					//��Ģ�����õ㼸��Ϊ0
					if(mushroom[i - 1][j - 1] == 1){
						p[i][j] = 0;
					}
					//�߽��ʱ�򣬸���Ϊ1�����򵽸õ�ļ���Ϊ0.5
					else{
						p[i][j] = p[i - 1][j] * (j == M ? 1 : 0.5) + p[i][j - 1] * (i == N ? 1 : 0.5);
					}
				}
			}
		}
		//�����յ����
		return p[N][M];
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextInt()){
			//����ݵش�СN��M��Ģ����K
			int N = input.nextInt();
			int M = input.nextInt();
			int K = input.nextInt();
			//����Ģ������
			int[] x = new int[K];
			int[] y = new int[K];
			for(int i = 0; i < K; i++){
				x[i] = input.nextInt();
				y[i] = input.nextInt();
			}
			//������ά���飬��ʼ��Ϊ0
			int[][] mushroom = new int[N][M];
			calMush(mushroom, x, y, K);
			/* ����˼·
			//����ֵ��count[0]Ϊ����·����count[1]Ϊ����������·��
			int[] count = {0, 0};
			count = step(mushroom, N - 1, M - 1, 0, 0, count, true);
			float prob = (float)count[1] / (float)count[0];
			*/
			//��ʼ�����ʾ�������ֵΪ0�ı߿�
			double[][] p = new double[N + 1][M + 1];
			double prob = getProb(mushroom, p, N, M);
			System.out.println(String.format("%.2f", prob));
		}
	}
}
