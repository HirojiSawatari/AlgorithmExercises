import java.util.*;

public class Count {
	public static int getAns(String str){
		//��¼��ʼ�±�
		int head = 0, count = 0, a, len, num;
		//��¼ǰһ���������ʼ��Ϊ�Ӻ�
		char cb = '+';
		//�����ַ���
		len = str.length();
		for(int i = 1; i < len; i++){
			//��ȡ��ǰ�ַ�
			char c = str.charAt(i);
			//��ǰΪ�����
			if(c == '+' || c == '-' || c == '*' || i == len - 1){
				//֮ǰ�ַ�λ��
				if(i == len - 1){
					num = len - head - 1;
				}
				else{
					num = i - head - 1;
				}
				a = 0;
				//�ָ������ǰ������a
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
					//��¼��ǰ�����
					cb = c;
					//��¼ͷ�±�
					head = i + 1;
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			//�����ַ���
			String str = input.next();
			int count = getAns(str);
			System.out.println(count);
		}
	}
}
