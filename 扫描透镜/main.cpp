#include <stdio.h>
#include <string.h>

/*
	在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,而且蘑菇是隐形的.只
	有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,于是他回了一趟战争学院,买了2个扫描透镜,一个
	扫描透镜可以扫描出(3*3)方格中所有的蘑菇,然后兰博就可以清理掉一些隐形的蘑菇.
	问:兰博最多可以清理多少个蘑菇?
	注意：每个方格被扫描一次只能清除掉一个蘑菇。
	
	输入描述:
	第一行三个整数:N,M,K,(1≤N,M≤20,K≤100),N,M代表了草地的大小;
	接下来K行,每行两个整数x,y(1≤x≤N,1≤y≤M).代表(x,y)处提莫种了一个蘑菇.
	一个方格可以种无穷个蘑菇.
	
	
	输出描述:
	输出一行,在这一行输出一个整数,代表兰博最多可以清理多少个蘑菇.
*/
 
int secondScan(int curgrass[22][22],int maxcorner[],int N,int M,int K){
	int a,b,i,j,num,curmax=0;
	//范围内每个区块清除一个蘑菇 
	for(i=maxcorner[0];i<maxcorner[0]+3;i++){
		for(j=maxcorner[1];j<maxcorner[1]+3;j++){
			if(curgrass[i][j]>0){
	    		curgrass[i][j]=0;
			}
		}
	}
	//第二个扫描透镜
	for(a=0;a<N-2;a++){
		for(b=0;b<M-2;b++){
			num=0;
			//统计每个蘑菇附近3*3区域有多少个有蘑菇的区块 
			for(i=a;i<a+3;i++){
				for(j=b;j<b+3;j++){
					if(curgrass[i][j]>0){
						num++;
					}
				}
			}
			if(curmax<num){
				curmax=num;
			}
		}
	}
	return curmax;
}

int main(){
	int N,M,K;
	//输入行数N，列数M，蘑菇树K
	while(scanf("%d %d %d",&N,&M,&K)!=EOF){
		int a,b,i,j,x[K],y[K],num,max=0,count=0;
		for(i=0;i<K;i++){
			//输入每个蘑菇的坐标
			scanf("%d %d",&x[i],&y[i]);
		}
		//创建场地（保留2个网格宽度的右下边框保证遍历时不会溢出）（可能会有多个最多扫描点，分别进行第二次扫描获取最佳值） 
		int grass[20+2][20+2],maxcorner[324][2],maxcount=0,mp,curmax;
		//初始值为0没有蘑菇 
		memset(grass,0,sizeof(grass));
		//初始化maxcorner值为0 
		memset(maxcorner,0,sizeof(maxcorner));
		for(i=0;i<K;i++){
			//输入的坐标是从1开始，需减1 
			x[i]--;
			y[i]--;
			//有蘑菇的区块加一（一个区块可以有无限个蘑菇）
			grass[x[i]][y[i]]++;
		}
		//第一个扫描透镜（注意：可能左上角区块不为蘑菇时最大） 
		for(a=0;a<N-2;a++){
			for(b=0;b<M-2;b++){
				num=0;
				//统计每个点右下3*3区域有多少个有蘑菇的区块，实时坐标为(a,b) 
				for(i=a;i<a+3;i++){
					for(j=b;j<b+3;j++){
						if(grass[i][j]>0){
							num++;
						}
					}
				}
				if(max<num){
					//清空maxcorner数组 
					memset(maxcorner,0,sizeof(maxcorner));
					maxcount=1;
					max=num;
					//记录最大区域左上角点  坐标
					maxcorner[0][0]=a;
					maxcorner[0][1]=b;
				}
				else if(max==num){
					//记录相同最大值左上角点的xy坐标 
					maxcorner[maxcount][0]=a;
					maxcorner[maxcount][1]=b;
					maxcount++;
				}
			}
		}
		count+=max;
		max=0;
		for(mp=0;mp<maxcount;mp++){
			curmax=secondScan(grass,maxcorner[mp],N,M,K);	        
			//此时最大值与之前比较获取此次遍历的最佳值 
			if(curmax>max){
				max=curmax;
			}
		}
		count+=max;
		printf("%d\n",count);
	}
}
