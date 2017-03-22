import java.util.*;

/*
 * 小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
 * 这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个
 * 约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，
 * 他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
 * 例如：
 * N = 4，M = 24：
 * 4->6->8->12->18->24
 * 于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板 
 *
 * 输入描述:
 * 输入为一行，有两个整数N，M，以空格隔开。
 * (4 ≤ N ≤ 100000)
 * (N ≤ M ≤ 100000)
 * 
 * 输出描述:
 * 输出小易最少需要跳跃的步数,如果不能到达输出-1
 */

public class JumpBoard {
	//约数数组（ArrayList方便插入不定个数的数字）
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
		//NM相等，表示此人现在就在该点上
		if(N == M){
			return 0;
		}
		//到达该位置需要的最短步数
		int[] step = new int[M + 1];
		//初始化为最大值
		for(int i = 0; i <= M; i++){
			step[i] = Integer.MAX_VALUE;
		}
		//第一个点需要步数为0
		step[N] = 0;
		for(int i = N; i <= M; i++){
			//之前无点能到达该点，直接跳过继续遍历
			if(step[i] == Integer.MAX_VALUE){
				continue;
			}
			//得到约数数组
			ArrayList<Integer> list = calList(i);
			for(int j = 0; j < list.size(); j++){
				int x = list.get(j);
				//不越界
				if(i + x <= M){
					//比较是当前点走一步到该点较近还是其之前路径到该点较近
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
			//输入起点和终点
			int N = input.nextInt();
			int M = input.nextInt();
			System.out.println(calStep(N, M));
		}
	}
}
