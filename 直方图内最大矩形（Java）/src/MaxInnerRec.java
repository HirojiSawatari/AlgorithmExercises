import java.util.*;

/*
 * 题目描述
 * 有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。比如，对于
 * 直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。
 * 给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int
 * 范围内。
 */

public class MaxInnerRec {
	public static int countArea(int[] A, int n) {
		// write code here
		//初始化最大矩形面积
		int area, maxarea = 0;
		//遍历每一根直方柱
		for(int i = 0; i < n; i++){
			//初始化宽度
			int l = 1;
			//遍历该直方柱之后的直方柱
			for(int j = (i + 1); j < n; j++){
				//此时的直方柱比此次遍历的第一根直方柱要短则中断遍历
				if(A[j] < A[i]){
					break;
				}
				//此时的直方柱不短于第一根，宽度加一
				l++;
			}
			//计算此时矩形面积
			area = l * A[i];
			//记录最大面积
			if(area > maxarea){
				maxarea = area;
			}
			//遍历该直方柱之前的直方柱
			for(int j = (i - 1); j > -1; j--){
				//此时的直方柱比此次遍历的最后一根直方柱要短则中断遍历
				if(A[j] < A[i]){
					break;
				}
				//此时的直方柱不短于最后根，宽度加一
				l++;
			}
			//计算此时矩形面积
			area = l * A[i];
			//记录最大面积
			if(area > maxarea){
				maxarea = area;
			}
		}
		return maxarea;
	}
	
	public static void main(String[] args) {
		int n;
		Scanner input = new Scanner(System.in);
		//输入总宽度
		n = input.nextInt();
		int A [] = new int [n];
		for(int i = 0; i < n; i++){
			A[i] = input.nextInt();
		}
		int maxarea = countArea(A, n);
		System.out.println(maxarea);
	}

}
