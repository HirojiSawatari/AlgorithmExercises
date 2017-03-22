import java.util.*;

/*
 * С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
 * ����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��
 * Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬
 * �����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
 * ���磺
 * N = 4��M = 24��
 * 4->6->8->12->18->24
 * ����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ�� 
 *
 * ��������:
 * ����Ϊһ�У�����������N��M���Կո������
 * (4 �� N �� 100000)
 * (N �� M �� 100000)
 * 
 * �������:
 * ���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
 */

public class JumpBoard {
	//Լ�����飨ArrayList������벻�����������֣�
	public static ArrayList<Integer> calList(int num){
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 2; i * i <= num; i++){
			if(num % i == 0){
				list.add(i);
				if(num / i != i){
					list.add(num / i);
				}
			}
		}
		return list;
	}
	
	public static int calStep(int N, int M){
		//NM��ȣ���ʾ�������ھ��ڸõ���
		if(N == M){
			return 0;
		}
		//�����λ����Ҫ����̲���
		int[] step = new int[M + 1];
		//��ʼ��Ϊ���ֵ
		for(int i = 0; i <= M; i++){
			step[i] = Integer.MAX_VALUE;
		}
		//��һ������Ҫ����Ϊ0
		step[N] = 0;
		for(int i = N; i <= M; i++){
			//֮ǰ�޵��ܵ���õ㣬ֱ��������������
			if(step[i] == Integer.MAX_VALUE){
				continue;
			}
			//�õ�Լ������
			ArrayList<Integer> list = calList(i);
			for(int j = 0; j < list.size(); j++){
				int x = list.get(j);
				//��Խ��
				if(i + x <= M){
					//�Ƚ��ǵ�ǰ����һ�����õ�Ͻ�������֮ǰ·�����õ�Ͻ�
					step[i + x] = Math.min(step[i + x], step[i] + 1);
				}
			}
		}
		if(step[M] == Integer.MAX_VALUE){
			return -1;
		}
		else{
			return step[M];
		}
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNextInt()){
			//���������յ�
			int N = input.nextInt();
			int M = input.nextInt();
			System.out.println(calStep(N, M));
		}
	}
}
