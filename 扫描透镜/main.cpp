#include <stdio.h>
#include <string.h>

/*
	��N*M�Ĳݵ���,��Ī����K��Ģ��,Ģ����ը����������,��������óȻȥ��,����Ģ�������ε�.ֻ
	��һ�ֽ���ɨ��͸������Ʒ����ɨ������ε�Ģ��,����������һ��ս��ѧԺ,����2��ɨ��͸��,һ��
	ɨ��͸������ɨ���(3*3)���������е�Ģ��,Ȼ�������Ϳ��������һЩ���ε�Ģ��.
	��:����������������ٸ�Ģ��?
	ע�⣺ÿ������ɨ��һ��ֻ�������һ��Ģ����
	
	��������:
	��һ����������:N,M,K,(1��N,M��20,K��100),N,M�����˲ݵصĴ�С;
	������K��,ÿ����������x,y(1��x��N,1��y��M).����(x,y)����Ī����һ��Ģ��.
	һ����������������Ģ��.
	
	
	�������:
	���һ��,����һ�����һ������,��������������������ٸ�Ģ��.
*/
 
int secondScan(int curgrass[22][22],int maxcorner[],int N,int M,int K){
	int a,b,i,j,num,curmax=0;
	//��Χ��ÿ���������һ��Ģ�� 
	for(i=maxcorner[0];i<maxcorner[0]+3;i++){
		for(j=maxcorner[1];j<maxcorner[1]+3;j++){
			if(curgrass[i][j]>0){
	    		curgrass[i][j]=0;
			}
		}
	}
	//�ڶ���ɨ��͸��
	for(a=0;a<N-2;a++){
		for(b=0;b<M-2;b++){
			num=0;
			//ͳ��ÿ��Ģ������3*3�����ж��ٸ���Ģ�������� 
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
	//��������N������M��Ģ����K
	while(scanf("%d %d %d",&N,&M,&K)!=EOF){
		int a,b,i,j,x[K],y[K],num,max=0,count=0;
		for(i=0;i<K;i++){
			//����ÿ��Ģ��������
			scanf("%d %d",&x[i],&y[i]);
		}
		//�������أ�����2�������ȵ����±߿�֤����ʱ��������������ܻ��ж�����ɨ��㣬�ֱ���еڶ���ɨ���ȡ���ֵ�� 
		int grass[20+2][20+2],maxcorner[324][2],maxcount=0,mp,curmax;
		//��ʼֵΪ0û��Ģ�� 
		memset(grass,0,sizeof(grass));
		//��ʼ��maxcornerֵΪ0 
		memset(maxcorner,0,sizeof(maxcorner));
		for(i=0;i<K;i++){
			//����������Ǵ�1��ʼ�����1 
			x[i]--;
			y[i]--;
			//��Ģ���������һ��һ��������������޸�Ģ����
			grass[x[i]][y[i]]++;
		}
		//��һ��ɨ��͸����ע�⣺�������Ͻ����鲻ΪĢ��ʱ��� 
		for(a=0;a<N-2;a++){
			for(b=0;b<M-2;b++){
				num=0;
				//ͳ��ÿ��������3*3�����ж��ٸ���Ģ�������飬ʵʱ����Ϊ(a,b) 
				for(i=a;i<a+3;i++){
					for(j=b;j<b+3;j++){
						if(grass[i][j]>0){
							num++;
						}
					}
				}
				if(max<num){
					//���maxcorner���� 
					memset(maxcorner,0,sizeof(maxcorner));
					maxcount=1;
					max=num;
					//��¼����������Ͻǵ�  ����
					maxcorner[0][0]=a;
					maxcorner[0][1]=b;
				}
				else if(max==num){
					//��¼��ͬ���ֵ���Ͻǵ��xy���� 
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
			//��ʱ���ֵ��֮ǰ�Ƚϻ�ȡ�˴α��������ֵ 
			if(curmax>max){
				max=curmax;
			}
		}
		count+=max;
		printf("%d\n",count);
	}
}
