import java.util.*;

/*��Ŀ����
 * ����һ���ַ��������Ƿ���ͨ�����һ����ĸ�����Ϊ���Ĵ���
 * 
 * ��������:
 * һ��һ����Сд��ĸ���ɵ��ַ������ַ�������С�ڵ���10��
 * 
 * �������:
 * �����(YES\NO).
 */

public class Palindrome {
	public static boolean isPal(String str){
		boolean b = false;
		//���������м����
		for(int i = 0, j = str.length() - 1; i < j; i++, j--){
			//���ֲ�ͬ
			if(str.charAt(i) != str.charAt(j)){
				//�Ѿ�����һ�Σ���������
				if(b == true){
					b = false;
					break;
				}
				else{
					//�ж������Ƿ���һ�����
					if((str.charAt(i + 1) == str.charAt(j))){
						b = true;
						i++;
					}
					else if((str.charAt(i) == str.charAt(j - 1))){
						b = true;
						j--;
					}
					//�����ϻ���
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
