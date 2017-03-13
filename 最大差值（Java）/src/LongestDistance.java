import java.util.*;

/*
 * ��Ŀ����
 * ��һ����Ϊn������A��������0��a��b<n��A[b]-A[a]�����ֵ��
 * ��������A�����Ĵ�Сn���뷵������ֵ
 * */

public class LongestDistance {
	public static int getDis(int[] A, int n) {
		// write code here
		int dis = 0, min;
		//����ͨ���������Сֵ�õ�����ֵ����ʼ����СֵΪ��һ������
		min = A[0];
		//����ֻ��һ������ʱ�޷��õ���ֵ
		if(n > 0){
			for(int i = 1; i < n; i ++){
				//���ָ�С����Сֵ
				if(A[i] < min){
					min = A[i];
				}
				//���ָ���Ĳ�ֵ
				if(A[i] - min > dis){
					dis = A[i] - min;
				}
			}
		}
		return dis;
	}
	public static void main(String[] args) {
		//Scanner������
		Scanner input = new Scanner(System.in);
		//���������Сn
		int n = input.nextInt(); 
		int A[] = new int [n];
		//����������ֵ
		for(int i = 0; i < n;i ++){
			A[i] = input.nextInt();
		}
		int dis = getDis(A, n);
		System.out.println(dis);
	}
}