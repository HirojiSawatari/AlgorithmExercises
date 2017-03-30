import java.util.*;

/*
 *题目描述：
 *给定一个段落，由 N 个句子组成。第 i 个句子的长度为 L[i]，包含的单词个数为 W[i]。
 *句子不包含任何除字母和空格( ) 外的符号。
 *每个句子内部，含有若干个单词，由空格( ) 分隔。句子不会包含连续的空格。
 *
 *随后给定 M 个查询，每个查询包含一个句子，需要在段落中寻找相同单词数量最多的句子。重复的单词只计一次，且不区分大小写。
 *输入数据将保证结果是存在且唯一的。
 *
 *输入
 *第一行是两个整数 N 和 M。
 *接下来的 N+M 行，每行包含一个句子。
 *前 N 行代表段落中的句子，后 M 行表示查询。
 *
 *输出
 *输出 M 行，每行代表查询的结果
 */

public class Paragraph {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextInt()){
			int N = input.nextInt();
			int M = input.nextInt();
			//去空值
			String temp = input.nextLine();
			//原段落
			String[] para = new String[N];
			for(int i = 0; i < N; i++){
				para[i] = input.nextLine();
			}
			//查询
			String[] sear = new String[M];
			for(int i = 0; i < M; i++){
				sear[i] = input.nextLine();
			}
			//切割
			String[][] paraWord = new String[N][];
			for(int i = 0; i < N; i++){
				//通过分析空格截取
				paraWord[i] = para[i].split(" ");
				for(int j = 0; j < paraWord[i].length; j++){
					//去掉括号
					if(paraWord[i][j].charAt(0) == '('){
						paraWord[i][j] = paraWord[i][j].substring(1, paraWord[i][j].length() - 1);
					}
				}
			}
			String[][] searWord = new String[M][];
			for(int i = 0; i < M; i++){
				//通过分析空格截取
				searWord[i] = sear[i].split(" ");
				for(int j = 0; j < searWord[i].length; j++){
					//去掉括号
					if(searWord[i][j].charAt(0) == '('){
						searWord[i][j] = searWord[i][j].substring(1, searWord[i][j].length() - 1);
					}
				}
			}
			//查询
			for(int i = 0; i < M; i++){
				int maxcount = 0, count, maxj = 0;
				//遍历句子
				for(int j = 0; j < N; j++){
					count = 0;
					for(int k = 0; k < paraWord[j].length; k++){
						for(int l = 0; l < searWord[i].length; l++){
							if(paraWord[j][k].equals(searWord[i][l])){
								count++;
							}
						}
					}
					if(count > maxcount){
						maxcount = count;
						maxj = j;
					}
				}
				System.out.println(para[maxj]);
			}
		}
	}
}
