#include <stdio.h>

/*
	Сv������n�ſΣ�ÿ�Ŷ��п��ԣ�Ϊ���õ���ѧ��Сv�������Լ���ƽ���ɼ�����Ϊavg��ÿ�ſ���ƽ
	ʱ�ɼ��Ϳ��Գɼ���ɣ�����Ϊr��������֪��ÿ�ſε�ƽʱ�ɼ�Ϊai,���������ſεĿ��Գɼ�����һ
	�ֵĻ���СvҪ��bi��ʱ�临ϰ������ϰ�Ļ���Ȼ����0�֡�ͬʱ������Ȼ���Է��ָ�ϰ���ٶ�Ҳ������
	���������ֵķ�����Ϊ���õ���ѧ��Сv����Ҫ������ʱ�临ϰ��
	
	��������:
	��һ����������n,r,avg(n���ڵ���1С�ڵ���1e5��r���ڵ���1С�ڵ���1e9,avg���ڵ���1С�ڵ���1e6)��
	������n�У�ÿ����������ai��bi����С�ڵ���1e6���ڵ���1
	
	
	�������:
	һ������𰸡�
*/

int calculate(int n,int r,int avg){
	int i,j,temp;
	long count=0;
	int a[n],b[n];
	long fulltime[n];
	long time=0;
	//���루ƽʱ�ɼ�a��ÿ����һ������ʱ��b�� 
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	//������ƴﵽ����ʱ����ʱ�䣬�Լ��������÷�֮��
	for(i=0;i<n;i++){	
		count+=a[i];
		fulltime[i]=(r-a[i])*b[i];
	}
	//���������÷��ѳ���ƽ���ּ��ɲ���ϰ 
	if(count<(avg*n)){
		//����ÿ��һ������ʱ���С��������ͬʱ����˳������aƽʱ�ɼ�,bÿ�õ�һ������ʱ�����飩����Ӧ���Եõ���������ʱ������ 
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++){	
				if(b[j]>b[j+1]){	//һ�ֺ�ʱ��С����ǰ�� 
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
		//���㻹�����
		long needpoint,curpoint;
		needpoint=(avg*n)-count;
		for(i=0;i<n;i++){
			//�ÿ����ֺ���õ��ķ���
			curpoint=needpoint-(r-a[i]);
			//�˿γ����ֺ󳬳�Ӧ��ƽ����
			if(curpoint<0){
				time+=(needpoint*b[i]);
				break;
			}
			//�˿γ�������Ȼ�ﲻ��ƽ����
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
	//���루�γ���n������r��ƽ����avg�� 
	while(scanf("%d %d %d",&n,&r,&avg)!=EOF){
		calculate(n,r,avg);
	}
}
