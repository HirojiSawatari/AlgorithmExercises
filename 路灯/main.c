#include <stdio.h>

/*
	一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai，每盏灯可以覆盖到的最远距
	离为d，为了照明需求，所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。
	
	输入描述:
	每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0
	小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。
	
	
	输出描述:
	输出答案，保留两位小数。
*/

int main(){
	int n,l;
	//输入路灯数目n和道路长度l
	while(scanf("%d %d",&n,&l)!=EOF){
		int a[n],i,j,temp;
		float d,max=0.0,space;
		for(i=0;i<n;i++){
			//输入每个路灯的坐标值
			scanf("%d",&a[i]);
		} 
		//对a数组进行从小到大冒泡排序
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		} 
		//遍历获取最大间隔
		for(i=0;i<n-1;i++){
			space=a[i+1]-a[i];
			if(space>max){
				max=space;
			}
		}
		d=max/2;
		//假如起止点无路灯，首尾两路灯需要照亮至起止点 
		if(a[0]!=0){
			space=a[0];
			if(space>d){
				d=space;
			}
		}
		if(a[n-1]!=l){
			space=l-a[n-1];
			if(space>d){
				d=space;
			}
		} 
		printf("%.2f\n",d);
	}
}
