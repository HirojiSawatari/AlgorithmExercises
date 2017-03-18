import java.util.*;

/*
 * 题目描述
 * 请设计一个高效算法，再给定的字符串数组中，找到包含"Coder"的字符串(不区分大小写)，并将其作为一个新的
 * 数组返回。结果字符串的顺序按照"Coder"出现的次数递减排列，若两个串中"Coder"出现的次数相同，则保持
 * 他们在原数组中的位置关系。
 * 
 * 给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300,其中每个串的长度小于等于200。
 * 同时保证一定存在包含coder的字符串。
 */

public class Coder {
	public static String[] findCoder(String[] A, int n) {
		// write code here
		int temp, i, j, total = 0;
		//字符串coder个数，初始化为0
		int[] num = new int[n];
		//遍历所有字符串
		for(i = 0; i < n; i++){
			num[i] = 0;
			//遍历当前字符串所有字母至倒数第五个为止（之后已经容不下coder）
			for(j = 0; j < A[i].length() - 4; j++){
				//发现字母C或c
				if(A[i].charAt(j) == 'C' || A[i].charAt(j) == 'c'){
					//截取当前后五个字符不计大小写与coder进行比较
					if(A[i].substring(j, j + 5).equalsIgnoreCase("coder") == true){
						//发现相同，计数值加1
						num[i]++;
					}
				}
			}
			//确定当前字符串存在coder
			if(num[i] > 0){
				total++;
			}
		}
		//记录原始下标
		int[] code = new int[n];
		for(i = 0; i < n; i++){
			code[i] = i;
		}
		//对num从大到小冒泡排序，同时改变code顺序
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - 1 - i; j++){
				if(num[j] < num[j + 1]){
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
					temp = code[j];
					code[j] = code[j + 1];
					code[j + 1] = temp;
				}
			}
		}
		//新建字符串数组
		String[] fiA = new String[total];
		//存入存在coder的字符串
		for(i = 0; (i < n && num[i] > 0); i++){
			fiA[i] = A[code[i]];
		}
		return fiA;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//输入数组大小n
		int n = input.nextInt();
		String[] A = new String[n];
		for(int i = 0; i < n; i++){
			A[i] = input.next();
		}
		String[] fiA = findCoder(A, n);
		for(int i = 0; i < fiA.length; i++){
			System.out.println(fiA[i]);
		}
	}
}
