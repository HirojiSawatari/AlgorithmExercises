#include <iostream>
#include <math.h> 

/*
	题目描述
	果园里有一堆苹果，一共n头(n大于1小于9)熊来分，第一头为小东，它把苹果均分n份后，多出了一
	个，它扔掉了这一个，拿走了自己的一份苹果，接着第二头熊重复这一过程，即先均分n份，扔掉一
	个然后拿走一份，以此类推直到最后一头熊都是这样(最后一头熊扔掉后可以拿走0个，也算是n份均
	分)。问最初这堆苹果最少有多少个。
	
	给定一个整数n,表示熊的个数，返回最初的苹果数。保证有解。
*/ 

int getInitial(int n) {
	// write code here
	int i, j, count, curget; 
	//正推，从1开始假设这堆苹果有多少个 
	for(i = 1; ; i++){
		count = i;
		//模拟分苹果
		for(j = 0; j < n; j++){
			//当前熊能得到的苹果数，保证始终能扔掉一个 
			curget = (count - 1) / n;
			//保证整除或者拿走0个（拿走0个的情况必须为扔掉1个苹果后只剩下0个） 
			if((count - 1) % n==0 || count - 1 == 0){ 
				count = count - curget - 1;
				//扔掉一个苹果后还剩0个，即最后一个熊只能拿到0个，此时为最后一个熊无法继续分 
				if(count == 0){
					//j为已操作的熊数 
					j++;
					break;
				}
			} 
			//不符合整除条件，当前熊已经无法平分，不符合情况 
			else{
				break; 
			} 
		} 
		//所有熊都进行均分操作 
		if(j == n){
			break; 
		} 
	}
	return i;
}

int main() {
	int n, count;
	while(scanf("%d", &n) != EOF){
		count = getInitial(n);
		printf("%d\n", count);
	}
}
