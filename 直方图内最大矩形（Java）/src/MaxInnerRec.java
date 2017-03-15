import java.util.*;

/*
 * ��Ŀ����
 * ��һ��ֱ��ͼ����һ�����������ʾ������ÿ�еĿ��Ϊ1��������ֱ��ͼ��������������������磬����
 * ֱ��ͼ[2,7,9,4],���������������ε����Ϊ14(��[7,9]������7x2�ľ���)��
 * ����һ��ֱ��ͼA�������ܿ��n���뷵���������������ֱ֤��ͼ���С�ڵ���500����֤�����int
 * ��Χ�ڡ�
 */

public class MaxInnerRec {
	public static int countArea(int[] A, int n) {
		// write code here
		//��ʼ�����������
		int area, maxarea = 0;
		//����ÿһ��ֱ����
		for(int i = 0; i < n; i++){
			//��ʼ�����
			int l = 1;
			//������ֱ����֮���ֱ����
			for(int j = (i + 1); j < n; j++){
				//��ʱ��ֱ�����ȴ˴α����ĵ�һ��ֱ����Ҫ�����жϱ���
				if(A[j] < A[i]){
					break;
				}
				//��ʱ��ֱ���������ڵ�һ������ȼ�һ
				l++;
			}
			//�����ʱ�������
			area = l * A[i];
			//��¼������
			if(area > maxarea){
				maxarea = area;
			}
			//������ֱ����֮ǰ��ֱ����
			for(int j = (i - 1); j > -1; j--){
				//��ʱ��ֱ�����ȴ˴α��������һ��ֱ����Ҫ�����жϱ���
				if(A[j] < A[i]){
					break;
				}
				//��ʱ��ֱ������������������ȼ�һ
				l++;
			}
			//�����ʱ�������
			area = l * A[i];
			//��¼������
			if(area > maxarea){
				maxarea = area;
			}
		}
		return maxarea;
	}
	
	public static void main(String[] args) {
		int n;
		Scanner input = new Scanner(System.in);
		//�����ܿ��
		n = input.nextInt();
		int A [] = new int [n];
		for(int i = 0; i < n; i++){
			A[i] = input.nextInt();
		}
		int maxarea = countArea(A, n);
		System.out.println(maxarea);
	}

}
