import java.util.*;

/*
 * 题目描述
 * 对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
 * 
 * 给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。保证字符串中
 * 有重复字符，字符串的长度小于等于500。
 */

public class FirstRepeat {
	public static char findFirstRepeat(String A, int n) {
		// write code here
		//初始化字典字符串
		char[] disc = new char[n];
		//字典当前长度
		int i, j, disi = 0;
		//遍历字符串
		for(i = 0; i < n; i++){
			//遍历字典查找是否有相同字符
			for(j = 0; j < disi; j++){
				//发现相同值跳出循环
				if(disc[j] == A.charAt(i)){
					break;
				}
			}
			//j未遍历完毕，表示有相同字符，跳出循环
			if(j < disi){
				break;
			} 
			//无相同字符，当前字符存入字典
			else{
				disc[disi] = A.charAt(i);
				disi++;
			}
		}
		return A.charAt(i);
	}
	
	public static void main(String[] args) {
		int n;
		Scanner input = new Scanner(System.in);
		//字符串A
		String A = input.next();
		//字符串长度n
		n = input.nextInt();
		char loc = findFirstRepeat(A, n);
		System.out.println(loc);
	}
}
