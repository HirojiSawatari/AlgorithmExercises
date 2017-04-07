import java.util.*;

public class AutoPilot01 {
	//处理第一行数据
	public static int[][] changeNum(int a, int[][] map, String str){
		int b = 0;
		for(int i = 0; i < str.length(); i++){
			char c = str.charAt(i);
			//统计空格个数即统计每行数字个数
			if(c != ' '){
				map[a][b] = Integer.parseInt(String.valueOf(c));
				b++;
			}
		}
		return map;
	}
	
	public static int searchLine(int[][] map, int a, int b, int min, int cur){
		//障碍物
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
			//除了末尾数字外一个数字加上一个空格为一组
			int numcount = (str01.length() + 1) / 2;
			int[][] map = new int[numcount][numcount];
			//输入第一行数字
			map = changeNum(0, map, str01);
			//输入其他数字
			for (int i = 1; i < numcount; i++) {
				for (int j = 0; j < numcount; j++) {
					map[i][j] = input.nextInt();
				}
			}
			int min = searchLine(map, 0, 0, 0, 0);
		}
	}
}
