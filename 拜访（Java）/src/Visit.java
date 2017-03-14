import java.util.*;

/*
 * ��Ŀ����
 * ������һ���������۾�����Ҫ�ӹ�˾������ȥ�ݷ����ڵ��̼ң���֪����λ���Լ��̼ҵ�λ�ã���������
 * ���е�·��ͨ��ԭ����ֻ����������ѡ��һ��������������ѡ��һ���������������ж����ַ�������
 * �̼ҵ�ַ��
 * 
 * ����һ����ͼmap�����ĳ���n��m������1������λ�ã�2�����̼�λ�ã�-1�����ܾ����ĵ�����0
 * ������Ծ����ĵ������뷵�ط���������֤һ�����ںϷ�·������֤����ĳ���С�ڵ���10��
 */

public class Visit {
	//�ݹ�ɨ��·������ͼ���飬��ǰxy���꣬�յ����꣬·������
	public static int scanLine(int[][] map, int x, int y, int [] end, int count){
		//�����յ�
		if(x == end[0] && y == end[1]){
			return (count + 1);
		}
		//�ֱ����£������ߵ������
		int x1 = x, y1 = y + 1, x2 = x + 1, y2 = y;
		//�����жϴ�·�Ƿ�ͨ���ҵ�ǰ��δ������ٽ��еݹ飨���жϲ�����-1�ķŵ�����ֹ�����
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
		//��ʼ����������
		int manager [] = new int [2];
		//��ʼ���̼�λ��
		int shop [] = new int [2];
		//�ҵ�����λ�ú��̼�λ��
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				//��¼����λ��
				if(map[i][j] == 1){
					manager[0] = i;
					manager[1] = j;
				}
				//��¼�̼�λ��
				if(map[i][j] == 2){
					shop[0] = i;
					shop[1] = j;
				}
			}
		}
		//��������ͬһ������ֱ�ӷ���1
		if(manager[0] == shop[0] || manager[1] == shop[1]){
			return 1;
		} else {
			int start [] = new int [2];
			int end [] = new int [2];
			//������̼�λ�þ��������Ͻǣ�xy����С��Ϊ��ʼ�㣬���½�Ϊ�յ㣨xy�����
			start[0] = (manager[0] > shop[0]) ? shop[0] : manager[0];
			start[1] = (manager[1] > shop[1]) ? shop[1] : manager[1];
			end[0] = (manager[0] < shop[0]) ? shop[0] : manager[0];
			end[1] = (manager[1] < shop[1]) ? shop[1] : manager[1];
			int count = 0;
			//ɨ��·��
			count = scanLine(map, start[0], start[1], end, count);
			return count;
		}
		
	}
	
	public static void main(String[] args) {
		int n, m;
		Scanner input = new Scanner(System.in);
		//�����ͼ�߿�
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
