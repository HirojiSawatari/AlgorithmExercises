import java.util.*;

/*
 * ��Ŀ����
 * ����һ���ַ����������һ����Ч�㷨���ҵ���һ���ظ����ֵ��ַ���
 * 
 * ����һ���ַ���(��һ��ȫΪ��ĸ)A�����ĳ���n���뷵�ص�һ���ظ����ֵ��ַ�����֤�ַ�����
 * ���ظ��ַ����ַ����ĳ���С�ڵ���500��
 */

public class FirstRepeat {
	public static char findFirstRepeat(String A, int n) {
		// write code here
		//��ʼ���ֵ��ַ���
		char[] disc = new char[n];
		//�ֵ䵱ǰ����
		int i, j, disi = 0;
		//�����ַ���
		for(i = 0; i < n; i++){
			//�����ֵ�����Ƿ�����ͬ�ַ�
			for(j = 0; j < disi; j++){
				//������ֵͬ����ѭ��
				if(disc[j] == A.charAt(i)){
					break;
				}
			}
			//jδ������ϣ���ʾ����ͬ�ַ�������ѭ��
			if(j < disi){
				break;
			} 
			//����ͬ�ַ�����ǰ�ַ������ֵ�
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
		//�ַ���A
		String A = input.next();
		//�ַ�������n
		n = input.nextInt();
		char loc = findFirstRepeat(A, n);
		System.out.println(loc);
	}
}
