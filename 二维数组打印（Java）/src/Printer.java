import java.util.*;

/*题目描述
 * 有一个二维数组(n*n),写程序实现从右上角到左下角沿主对角线方向打印。
 * 给定一个二位数组arr及题目中的参数n，请返回结果数组。
 */

public class Printer {
	public static int[] arrayPrint(int[][] arr, int n) {
		// write code here
		int num[] = new int[(n * n)];
		//初始化指针在右上角
		int curx = 0;
		int cury = (n - 1);
		//记录此时左上右下直线最左上角的xy坐标
		int topx = curx;
		int topy = cury;
		for(int i = 0; i < (n * n); i++){
			//记录指针对应值
			num[i] = arr[curx][cury];
			//指针向右下方移动
			curx++;
			cury++;
			//指针从右边溢出，从左边继续开始向右下遍历（排除最右下角情况，下一步处理）
			if(cury == n && curx != n){
				topy--;
				curx = 0;
				cury = topy;
			}
			//指针从下边溢出，从下边继续开始向右下遍历
			else if(curx == n){
				topx++;
				curx = topx;
				cury = 0;
			}
		}
		return num;
	}
	
	public static void main(String[] args) {
		//Scanner类输入
		Scanner input = new Scanner(System.in);
		//输入数组大小n
		int n = input.nextInt();
		int[][] arr = new int [n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				arr[i][j] = input.nextInt();
			}
		}
		int[] num = new int [(n * n)]; 
		num = arrayPrint(arr, n);
		for(int i = 0; i < (n * n); i++){
			System.out.print(num[i] + " ");
		}
	}
}
