import java.util.*;

public class AutoPilot01 {
	//�����һ������
	public static int[][] changeNum(int a, int[][] map, String str){
		int b = 0;
		for(int i = 0; i < str.length(); i++){
			char c = str.charAt(i);
			//ͳ�ƿո������ͳ��ÿ�����ָ���
			if(c != ' '){
				map[a][b] = Integer.parseInt(String.valueOf(c));
				b++;
			}
		}
		return map;
	}
	
	public static int searchLine(int[][] map, int a, int b, int min, int cur){
		//�ϰ���
		if(map[a][b] == 1){
			return 0;
		}
		else{
			cur++;
		}
		return min;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String str01 = input.nextLine();
			//����ĩβ������һ�����ּ���һ���ո�Ϊһ��
			int numcount = (str01.length() + 1) / 2;
			int[][] map = new int[numcount][numcount];
			//�����һ������
			map = changeNum(0, map, str01);
			//������������
			for (int i = 1; i < numcount; i++) {
				for (int j = 0; j < numcount; j++) {
					map[i][j] = input.nextInt();
				}
			}
			int min = searchLine(map, 0, 0, 0, 0);
		}
	}
}
