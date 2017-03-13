import java.util.*;

/*
 *��Ŀ����
 *��4x4�������ϰ����˺ڰ����ӣ��ڰ���ɫ��λ�ú���Ŀ����������Ͻ�����Ϊ(1,1),���½�����Ϊ(4,4),��
 *��������һЩ��ת������Ҫ��һЩ����֧������Ϊ���ĵ����������ĸ����ӵ���ɫ���з�ת����������ת���������ɫ��
 *������������A��f,�ֱ�Ϊ��ʼ���̺ͷ�תλ�á����з�תλ�ù���3�����뷵�ط�ת������̡� 
 */

public class Flip {
	public static int[][] flipChess(int[][] A, int[][] f) {
		// write code here
		int x, y;
		//���嵥�η�ת����λ������
		int changeChess [][] = new int [4][2];
		//������Ҫ��תλ�ö�ά����
		for(int i = 0; i < 3; i ++){
			//����λ�������1��ʼ����Ҫת��Ϊ��0��ʼ
			x = f[i][0] - 1;
			y = f[i][1] - 1;
			changeChess[0][0] = x - 1;
			changeChess[0][1] = y;
			changeChess[1][0] = x + 1;
			changeChess[1][1] = y;
			changeChess[2][0] = x;
			changeChess[2][1] = y - 1;
			changeChess[3][0] = x;
			changeChess[3][1] = y + 1;
			//�����������ӷ�ת
			for(int j = 0; j < 4; j++){
				//��ʱ����δ���
				if((changeChess[j][0] >= 0) && (changeChess[j][0] < 4) && 
						(changeChess[j][1] >= 0) && (changeChess[j][1] < 4)){
					//1��0,0��1
					A[changeChess[j][0]][changeChess[j][1]] = (A[changeChess[j][0]][changeChess[j][1]] == 0) ? 1 : 0;
				}
			}
		}
		return A;
	}
	public static void main(String[] args) {
		int A [][] = new int [4][4];
		int f [][] = new int [3][2];
		//Scanner������
		Scanner input = new Scanner(System.in);
		//��������
		for(int i = 0; i < 4; i ++){
			for(int j = 0; j < 4; j ++){
				A[i][j] = input.nextInt();
			}
		}
		//���뷭ת��
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 2; j ++){
				f[i][j] = input.nextInt();
			}
		}
		A = flipChess(A, f);
		for(int i = 0; i < 4; i ++){
			System.out.print("[");
			for(int j = 0; j < 4; j ++){
				System.out.print(A[i][j]);
				if(j != 3){
					System.out.print(",");
				}
			}
			System.out.print("]");
		}
	}
}
