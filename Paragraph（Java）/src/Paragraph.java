import java.util.*;

/*
 *��Ŀ������
 *����һ�����䣬�� N ��������ɡ��� i �����ӵĳ���Ϊ L[i]�������ĵ��ʸ���Ϊ W[i]��
 *���Ӳ������κγ���ĸ�Ϳո�( ) ��ķ��š�
 *ÿ�������ڲ����������ɸ����ʣ��ɿո�( ) �ָ������Ӳ�����������Ŀո�
 *
 *������ M ����ѯ��ÿ����ѯ����һ�����ӣ���Ҫ�ڶ�����Ѱ����ͬ�����������ľ��ӡ��ظ��ĵ���ֻ��һ�Σ��Ҳ����ִ�Сд��
 *�������ݽ���֤����Ǵ�����Ψһ�ġ�
 *
 *����
 *��һ������������ N �� M��
 *�������� N+M �У�ÿ�а���һ�����ӡ�
 *ǰ N �д�������еľ��ӣ��� M �б�ʾ��ѯ��
 *
 *���
 *��� M �У�ÿ�д����ѯ�Ľ��
 */

public class Paragraph {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNextInt()){
			int N = input.nextInt();
			int M = input.nextInt();
			//ȥ��ֵ
			String temp = input.nextLine();
			//ԭ����
			String[] para = new String[N];
			for(int i = 0; i < N; i++){
				para[i] = input.nextLine();
			}
			//��ѯ
			String[] sear = new String[M];
			for(int i = 0; i < M; i++){
				sear[i] = input.nextLine();
			}
			//�и�
			String[][] paraWord = new String[N][];
			for(int i = 0; i < N; i++){
				//ͨ�������ո��ȡ
				paraWord[i] = para[i].split(" ");
				for(int j = 0; j < paraWord[i].length; j++){
					//ȥ������
					if(paraWord[i][j].charAt(0) == '('){
						paraWord[i][j] = paraWord[i][j].substring(1, paraWord[i][j].length() - 1);
					}
				}
			}
			String[][] searWord = new String[M][];
			for(int i = 0; i < M; i++){
				//ͨ�������ո��ȡ
				searWord[i] = sear[i].split(" ");
				for(int j = 0; j < searWord[i].length; j++){
					//ȥ������
					if(searWord[i][j].charAt(0) == '('){
						searWord[i][j] = searWord[i][j].substring(1, searWord[i][j].length() - 1);
					}
				}
			}
			//��ѯ
			for(int i = 0; i < M; i++){
				int maxcount = 0, count, maxj = 0;
				//��������
				for(int j = 0; j < N; j++){
					count = 0;
					for(int k = 0; k < paraWord[j].length; k++){
						for(int l = 0; l < searWord[i].length; l++){
							if(paraWord[j][k].equals(searWord[i][l])){
								count++;
							}
						}
					}
					if(count > maxcount){
						maxcount = count;
						maxj = j;
					}
				}
				System.out.println(para[maxj]);
			}
		}
	}
}
