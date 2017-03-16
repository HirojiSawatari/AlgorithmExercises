import java.util.*;

/*��Ŀ����
 * ��һ����ά����(n*n),д����ʵ�ִ����Ͻǵ����½������Խ��߷����ӡ��
 * ����һ����λ����arr����Ŀ�еĲ���n���뷵�ؽ�����顣
 */

public class Printer {
	public static int[] arrayPrint(int[][] arr, int n) {
		// write code here
		int num[] = new int[(n * n)];
		//��ʼ��ָ�������Ͻ�
		int curx = 0;
		int cury = (n - 1);
		//��¼��ʱ��������ֱ�������Ͻǵ�xy����
		int topx = curx;
		int topy = cury;
		for(int i = 0; i < (n * n); i++){
			//��¼ָ���Ӧֵ
			num[i] = arr[curx][cury];
			//ָ�������·��ƶ�
			curx++;
			cury++;
			//ָ����ұ����������߼�����ʼ�����±������ų������½��������һ������
			if(cury == n && curx != n){
				topy--;
				curx = 0;
				cury = topy;
			}
			//ָ����±���������±߼�����ʼ�����±���
			else if(curx == n){
				topx++;
				curx = topx;
				cury = 0;
			}
		}
		return num;
	}
	
	public static void main(String[] args) {
		//Scanner������
		Scanner input = new Scanner(System.in);
		//���������Сn
		int n = input.nextInt();
		int[][] arr = new int [n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				arr[i][j] = input.nextInt();
			}
		}
		int[] num = new int [(n * n)]; 
		num = arrayPrint(arr, n);
		for(int i = 0; i < (n * n); i++){
			System.out.print(num[i] + " ");
		}
	}
}
