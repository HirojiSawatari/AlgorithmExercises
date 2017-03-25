import java.util.*;

/*题目描述
 * 给定一个字符串，问是否能通过添加一个字母将其变为回文串。
 * 
 * 输入描述:
 * 一行一个由小写字母构成的字符串，字符串长度小于等于10。
 * 
 * 输出描述:
 * 输出答案(YES\NO).
 */

public class Palindrome {
	public static boolean isPal(String str){
		boolean b = false;
		//从两边向中间遍历
		for(int i = 0, j = str.length() - 1; i < j; i++, j--){
			//发现不同
			if(str.charAt(i) != str.charAt(j)){
				//已经跳过一次，不能再跳
				if(b == true){
					b = false;
					break;
				}
				else{
					//判断跳过是否下一组相等
					if((str.charAt(i + 1) == str.charAt(j))){
						b = true;
						i++;
					}
					else if((str.charAt(i) == str.charAt(j - 1))){
						b = true;
						j--;
					}
					//不符合回文
					else{
						break;
					}
				}
			}
		}
		return b;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String str = input.next();
			boolean isPal = isPal(str);
			if(isPal == true){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}
}
