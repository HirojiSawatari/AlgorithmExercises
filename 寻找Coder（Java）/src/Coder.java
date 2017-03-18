import java.util.*;

/*
 * ��Ŀ����
 * �����һ����Ч�㷨���ٸ������ַ��������У��ҵ�����"Coder"���ַ���(�����ִ�Сд)����������Ϊһ���µ�
 * ���鷵�ء�����ַ�����˳����"Coder"���ֵĴ����ݼ����У�����������"Coder"���ֵĴ�����ͬ���򱣳�
 * ������ԭ�����е�λ�ù�ϵ��
 * 
 * ����һ���ַ�������A�����Ĵ�Сn���뷵�ؽ�����顣��֤ԭ�����СС�ڵ���300,����ÿ�����ĳ���С�ڵ���200��
 * ͬʱ��֤һ�����ڰ���coder���ַ�����
 */

public class Coder {
	public static String[] findCoder(String[] A, int n) {
		// write code here
		int temp, i, j, total = 0;
		//�ַ���coder��������ʼ��Ϊ0
		int[] num = new int[n];
		//���������ַ���
		for(i = 0; i < n; i++){
			num[i] = 0;
			//������ǰ�ַ���������ĸ�����������Ϊֹ��֮���Ѿ��ݲ���coder��
			for(j = 0; j < A[i].length() - 4; j++){
				//������ĸC��c
				if(A[i].charAt(j) == 'C' || A[i].charAt(j) == 'c'){
					//��ȡ��ǰ������ַ����ƴ�Сд��coder���бȽ�
					if(A[i].substring(j, j + 5).equalsIgnoreCase("coder") == true){
						//������ͬ������ֵ��1
						num[i]++;
					}
				}
			}
			//ȷ����ǰ�ַ�������coder
			if(num[i] > 0){
				total++;
			}
		}
		//��¼ԭʼ�±�
		int[] code = new int[n];
		for(i = 0; i < n; i++){
			code[i] = i;
		}
		//��num�Ӵ�Сð������ͬʱ�ı�code˳��
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
		//�½��ַ�������
		String[] fiA = new String[total];
		//�������coder���ַ���
		for(i = 0; (i < n && num[i] > 0); i++){
			fiA[i] = A[code[i]];
		}
		return fiA;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//���������Сn
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
