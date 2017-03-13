import java.util.*;

/*
 * 题目描述
 * 有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
 * 给定数组A及它的大小n，请返回最大差值
 * */

public class LongestDistance {
	public static int getDis(int[] A, int n) {
		// write code here
		int dis = 0, min;
		//可以通过找最大最小值得到最大差值，初始化最小值为第一个数字
		min = A[0];
		//数组只有一个数字时无法得到差值
		if(n > 0){
			for(int i = 1; i < n; i ++){
				//发现更小的最小值
				if(A[i] < min){
					min = A[i];
				}
				//发现更大的差值
				if(A[i] - min > dis){
					dis = A[i] - min;
				}
			}
		}
		return dis;
	}
	public static void main(String[] args) {
		//Scanner类输入
		Scanner input = new Scanner(System.in);
		//输入数组大小n
		int n = input.nextInt(); 
		int A[] = new int [n];
		//依次输入数值
		for(int i = 0; i < n;i ++){
			A[i] = input.nextInt();
		}
		int dis = getDis(A, n);
		System.out.println(dis);
	}
}