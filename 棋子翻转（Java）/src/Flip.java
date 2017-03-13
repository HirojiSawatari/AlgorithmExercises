import java.util.*;

/*
 *题目描述
 *在4x4的棋盘上摆满了黑白棋子，黑白两色的位置和数目随机其中左上角坐标为(1,1),右下角坐标为(4,4),现
 *在依次有一些翻转操作，要对一些给定支点坐标为中心的上下左右四个棋子的颜色进行翻转，请计算出翻转后的棋盘颜色。
 *给定两个数组A和f,分别为初始棋盘和翻转位置。其中翻转位置共有3个。请返回翻转后的棋盘。 
 */

public class Flip {
	public static int[][] flipChess(int[][] A, int[][] f) {
		// write code here
		int x, y;
		//定义单次翻转棋子位置数组
		int changeChess [][] = new int [4][2];
		//遍历需要翻转位置二维数组
		for(int i = 0; i < 3; i ++){
			//输入位置坐标从1开始，需要转换为从0开始
			x = f[i][0] - 1;
			y = f[i][1] - 1;
			changeChess[0][0] = x - 1;
			changeChess[0][1] = y;
			changeChess[1][0] = x + 1;
			changeChess[1][1] = y;
			changeChess[2][0] = x;
			changeChess[2][1] = y - 1;
			changeChess[3][0] = x;
			changeChess[3][1] = y + 1;
			//上下左右棋子翻转
			for(int j = 0; j < 4; j++){
				//此时坐标未溢出
				if((changeChess[j][0] >= 0) && (changeChess[j][0] < 4) && 
						(changeChess[j][1] >= 0) && (changeChess[j][1] < 4)){
					//1变0,0变1
					A[changeChess[j][0]][changeChess[j][1]] = (A[changeChess[j][0]][changeChess[j][1]] == 0) ? 1 : 0;
				}
			}
		}
		return A;
	}
	public static void main(String[] args) {
		int A [][] = new int [4][4];
		int f [][] = new int [3][2];
		//Scanner类输入
		Scanner input = new Scanner(System.in);
		//输入棋盘
		for(int i = 0; i < 4; i ++){
			for(int j = 0; j < 4; j ++){
				A[i][j] = input.nextInt();
			}
		}
		//输入翻转点
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 2; j ++){
				f[i][j] = input.nextInt();
			}
		}
		A = flipChess(A, f);
		for(int i = 0; i < 4; i ++){
			System.out.print("[");
			for(int j = 0; j < 4; j ++){
				System.out.print(A[i][j]);
				if(j != 3){
					System.out.print(",");
				}
			}
			System.out.print("]");
		}
	}
}
