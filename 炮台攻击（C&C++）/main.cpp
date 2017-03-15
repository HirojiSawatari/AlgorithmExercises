#include <stdio.h>
#include <math.h>

/*
	题目描述
	兰博教训提莫之后,然后和提莫讨论起约德尔人,谈起约德尔人,自然少不了一个人,那 就是黑默丁
	格------约德尔人历史上最伟大的科学家. 提莫说,黑默丁格最近在思考一个问题:黑默丁格有三个
	炮台,炮台能攻击到距离它R的敌人 (两点之间的距离为两点连续的距离,例如(3,0),(0,4)之间的距
	离是5),如果一个炮台能攻击 到敌人,那么就会对敌人造成1×的伤害.黑默丁格将三个炮台放在N*M方
	格中的点上,并且给出敌人 的坐标. 问:那么敌人受到伤害会是多大?
	
	输入描述:
	第一行9个整数,R,x1,y1,x2,y2,x3,y3,x0,y0.R代表炮台攻击的最大距离,(x1,y1),(x2,y2),
	(x3,y3)代表三个炮台的坐标.(x0,y0)代表敌人的坐标.
	
	输出描述:
	输出一行,这一行代表敌人承受的最大伤害,(如果每个炮台都不能攻击到敌人,输出0×)
*/

int injury(int R, int x, int y, int x0, int y0){
	int a, b, inj = 0;
	float dist;
	//计算炮塔与敌人间的距离 
	a = fabs(x0 - x);
	b = fabs(y0 - y);
	dist = sqrt(pow(a, 2) + pow(b, 2));
	//若距离小于等于射程，则受到伤害 
	if(dist <= R){
		inj++; 
	}
	return inj; 
}

int shoot(int R, int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0){
	int totalinj = 0;
	totalinj += injury(R, x1, y1, x0, y0);
	totalinj += injury(R, x2, y2, x0, y0);
	totalinj += injury(R, x3, y3, x0, y0);
	printf("%dx\n", totalinj);
	return 0;
}

int main(){
	int R, x1, y1, x2, y2, x3, y3, x0, y0;
	while(scanf("%d %d %d %d %d %d %d %d %d", &R, &x1, &y1, &x2, &y2, &x3, &y3, &x0, &y0)!=EOF){
		shoot(R, x1, y1, x2, y2, x3, y3, x0, y0);
	}
}
