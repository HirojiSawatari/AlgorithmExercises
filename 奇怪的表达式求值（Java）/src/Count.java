import java.util.*;

public class Count {
	public static int getAns(String str){
		//记录初始下标
		int head = 0, count = 0, a, len, num;
		//记录前一运算符，初始化为加号
		char cb = '+';
		//遍历字符串
		len = str.length();
		for(int i = 1; i < len; i++){
			//获取当前字符
			char c = str.charAt(i);
			//当前为运算符
			if(c == '+' || c == '-' || c == '*' || i == len - 1){
				//之前字符位数
				if(i == len - 1){
					num = len - head - 1;
				}
				else{
					num = i - head - 1;
				}
				a = 0;
				//恢复运算符前数字至a
				if(i == len - 1){
					for(int j = head; j < len; j++){
						a += (str.charAt(j) - '0') * Math.pow(10, num);
						num--;
					}
				}
				else{
					for(int j = head; j < i; j++){
						a += (str.charAt(j) - '0') * Math.pow(10, num);
						num--;
					}
				}
				if(cb == '+'){
					count += a;
				}
				else if(cb == '-'){
					count -= a;
				}
				else{
					count *= a;
				}
				if(i != len - 1){
					//记录当前运算符
					cb = c;
					//记录头下标
					head = i + 1;
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			//输入字符串
			String str = input.next();
			int count = getAns(str);
			System.out.println(count);
		}
	}
}
