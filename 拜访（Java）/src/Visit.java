import java.util.*;

/*
 * 题目描述
 * 现在有一个城市销售经理，需要从公司出发，去拜访市内的商家，已知他的位置以及商家的位置，但是由于
 * 城市道路交通的原因，他只能在左右中选择一个方向，在上下中选择一个方向，现在问他有多少种方案到达
 * 商家地址。
 * 
 * 给定一个地图map及它的长宽n和m，其中1代表经理位置，2代表商家位置，-1代表不能经过的地区，0
 * 代表可以经过的地区，请返回方案数，保证一定存在合法路径。保证矩阵的长宽都小于等于10。
 */

public class Visit {
	//递归扫描路径（地图数组，当前xy坐标，终点坐标，路线数）
	public static int scanLine(int[][] map, int x, int y, int [] end, int count){
		//到达终点
		if(x == end[0] && y == end[1]){
			return (count + 1);
		}
		//分别向下，向右走的坐标点
		int x1 = x, y1 = y + 1, x2 = x + 1, y2 = y;
		//首先判断此路是否通畅且当前点未溢出，再进行递归（把判断不等于-1的放到最后防止溢出）
		if(x1 <= end[0] && y1 <= end[1] && map[x1][y1] != -1){
			count = scanLine(map, x1, y1, end, count);
		}
		if(x2 <= end[0] && y2 <= end[1] && map[x2][y2] != -1){
			count = scanLine(map, x2, y2, end, count);
		}
		return count;
	}
	
	public static int countPath(int[][] map, int n, int m) {
		// write code here
		//初始化经理坐标
		int manager [] = new int [2];
		//初始化商家位置
		int shop [] = new int [2];
		//找到经理位置和商家位置
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				//记录经理位置
				if(map[i][j] == 1){
					manager[0] = i;
					manager[1] = j;
				}
				//记录商家位置
				if(map[i][j] == 2){
					shop[0] = i;
					shop[1] = j;
				}
			}
		}
		//两点若在同一条线上直接返回1
		if(manager[0] == shop[0] || manager[1] == shop[1]){
			return 1;
		} else {
			int start [] = new int [2];
			int end [] = new int [2];
			//经理和商家位置矩形中左上角（xy均最小）为起始点，右下角为终点（xy均最大）
			start[0] = (manager[0] > shop[0]) ? shop[0] : manager[0];
			start[1] = (manager[1] > shop[1]) ? shop[1] : manager[1];
			end[0] = (manager[0] < shop[0]) ? shop[0] : manager[0];
			end[1] = (manager[1] < shop[1]) ? shop[1] : manager[1];
			int count = 0;
			//扫描路径
			count = scanLine(map, start[0], start[1], end, count);
			return count;
		}
		
	}
	
	public static void main(String[] args) {
		int n, m;
		Scanner input = new Scanner(System.in);
		//输入地图高宽
		n = input.nextInt();
		m = input.nextInt();
		int map [][] = new int [n][m];
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				map[i][j] = input.nextInt();
			}
		}
		int count = countPath(map, n, m);
		System.out.println(count);
	}

}
