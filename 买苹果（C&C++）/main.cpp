#include <stdio.h>

/*
	小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋
	的包装(包装不可拆分)。 可是小易现在只想购买恰好n个苹果，小易想购买尽量少
	的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。 
	
	输入描述:
	输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果
	
	输出描述:
	输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1
*/

int canbuy(int n){
	//奇数直接无法购买 
	if(n % 2 != 0){
		return -1;	
	}
	//6个的情况 
	else if(n == 6){
		return 1; 
	}
	//能被8整除，直接买8袋装 
	else if(n % 8 == 0){
		return (n / 8);
	} 
	else{
		int i;
		//尽量多买8袋装 
		for(i = (n / 8); i > 0; i--){
			//能恰好购买 
			if((n - 8 * i) % 6 == 0){
				break; 
			}
		}
		//遍历完毕未找到符合条件的情况 
		if(i == 0){
			return -1;
		} 
		else{
			return i + ((n - 8 * i) / 6);
		}
	}
}

int main() {
	int n, total;
	while(scanf("%d", &n) != EOF){
		total = canbuy(n);
		printf("%d", total);
	}
}
