#include <stdio.h>

/*
	小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。每门课由平
	时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai,若想让这门课的考试成绩多拿一
	分的话，小v要花bi的时间复习，不复习的话当然就是0分。同时我们显然可以发现复习得再多也不会拿
	到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。
	
	输入描述:
	第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，
	接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1
	
	
	输出描述:
	一行输出答案。
*/

int calculate(int n,int r,int avg){
	int i,j,temp;
	long count=0;
	int a[n],b[n];
	long fulltime[n];
	long time=0;
	//输入（平时成绩a，每多拿一分所需时间b） 
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	//计算各科达到满分时所需时间，以及现在所得分之和
	for(i=0;i<n;i++){	
		count+=a[i];
		fulltime[i]=(r-a[i])*b[i];
	}
	//若现在所得分已超过平均分即可不复习 
	if(count<(avg*n)){
		//按照每得一分所需时间从小到大排序（同时按此顺序排序a平时成绩,b每得到一分所需时间数组）（不应该以得到满分所需时间排序） 
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++){	
				if(b[j]>b[j+1]){	//一分耗时较小者往前移 
					temp=fulltime[j+1];
					fulltime[j+1]=fulltime[j];
					fulltime[j]=temp;	
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
					temp=b[j+1];
					b[j+1]=b[j];
					b[j]=temp;
				}
			}
		}
		//计算还需分数
		long needpoint,curpoint;
		needpoint=(avg*n)-count;
		for(i=0;i<n;i++){
			//该课满分后还需得到的分数
			curpoint=needpoint-(r-a[i]);
			//此课程满分后超出应得平均分
			if(curpoint<0){
				time+=(needpoint*b[i]);
				break;
			}
			//此课程满分仍然达不到平均分
			else{
				time+=fulltime[i];
			}
			needpoint=curpoint;
		}
	}
	printf("%ld\n",time);	
	return 0;
}

int main(){
	int n,r,avg,time;
	//输入（课程数n，满分r，平均分avg） 
	while(scanf("%d %d %d",&n,&r,&avg)!=EOF){
		calculate(n,r,avg);
	}
}
