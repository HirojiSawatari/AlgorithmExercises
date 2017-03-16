import java.util.*;

/*
 * С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6��������
 * ���У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»���
 * �����ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����
 * 
 * ����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤
 * ÿ�������ֵ����100С��1000��
 */

public class Bonus {
	public static int getPrice(int[][] board, int curprice, int maxprice, int x, int y){
		int price1, price2;
		//δ�����ǰ�ܼ�ֵ���ϵ�ǰ����ļ�ֵ
		if(x <= 5 && y <= 5){
			curprice += board[x][y];
		}
		//�������½�
		if(x == 5 && y == 5){
			//��ǰ·���ܼ�ֵ����֮ǰ�ļ�ֵ
			if(curprice > maxprice){
				return curprice;
			}
			else{
				return maxprice;
			}
		}
		//δ������ֱ����»���������һ��
		if(x <= 5 && y <= 5){
			price1 = getPrice(board, curprice, maxprice, x + 1, y);
			price2 = getPrice(board, curprice, maxprice, x, y + 1);
			//�õ��ϴ�ļ۸�
			maxprice = (price1 > price2) ? price1 : price2;
			return maxprice;
		}
		return 0;
	}
	
	public static int getMost(int[][] board) {
		// write code here
		int maxprice = 0;
		//�ݹ麯����ȡ����ֵ
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
