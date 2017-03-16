import java.util.*;

/*
 * 小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上
 * 进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者
 * 向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。
 * 
 * 给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证
 * 每个礼物价值大于100小于1000。
 */

public class Bonus {
	public static int getPrice(int[][] board, int curprice, int maxprice, int x, int y){
		int price1, price2;
		//未溢出当前总价值加上当前礼物的价值
		if(x <= 5 && y <= 5){
			curprice += board[x][y];
		}
		//到达右下角
		if(x == 5 && y == 5){
			//当前路线总价值大于之前的价值
			if(curprice > maxprice){
				return curprice;
			}
			else{
				return maxprice;
			}
		}
		//未溢出，分别向下或者向右走一步
		if(x <= 5 && y <= 5){
			price1 = getPrice(board, curprice, maxprice, x + 1, y);
			price2 = getPrice(board, curprice, maxprice, x, y + 1);
			//得到较大的价格
			maxprice = (price1 > price2) ? price1 : price2;
			return maxprice;
		}
		return 0;
	}
	
	public static int getMost(int[][] board) {
		// write code here
		int maxprice = 0;
		//递归函数获取最大价值
		maxprice = getPrice(board, 0, maxprice, 0, 0);
		return maxprice;
	}
	
	public static void main(String[] args) {
		int board[][] = new int [6][6];
		Scanner input = new Scanner(System.in);
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				board[i][j] = input.nextInt();
			}
		}
		int maxprice = getMost(board);
		System.out.println(maxprice);
	}

}
