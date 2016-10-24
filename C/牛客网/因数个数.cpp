#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 100000
/*
���Ӹ���
ʱ������ 1000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
һ�����������Էֽ��һ����������Ļ�������36=2*2*3*3��������2��3�������ӡ�
NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����
�����������ӣ�������������������Σ���������������ҪС�ڵ��ڣ��������1/2���ɴ˿�֪��100000���ڵ�������󲻴��� 
*/
int isprime(int a){
	if(a<2)return 0;
	if(a==2)return 1;
	if(a%2==0)return 0;
	for(int i=3;i<=sqrt(a);i+=2){
		if(a%i==0)return 0;
	}
	return 1;
}


int main(){
    int n;
    int a[N];
    a[0]=2;a[1]=3;a[2]=5;
	int num=2;
    for(int i=5;i<N;i++){
    	if(isprime(i))a[num++]=i;
	}
//	printf("%d",num);��ͳ�ƣ���Ч���ݷ�Χ�ڹ���9ǧ���������Ҳ����˵�����Գ�Ϊ���ӵ�������ô�࣬���������ȥ��������ʡʱ��
//��˵����ģ��͵���ż����ʡȥһ���ˡ� 
//	for(int i=0;i<num;i++)printf("%d ",a[i]);
	
    while((scanf("%d",&n))!=EOF){
		int cnt=0;
		for(int i=0;i<num;i++){
			if(a[i]>n)break;
			if(n%a[i]==0){
				while(!(n%a[i]))n/=a[i];
			cnt++;	
			}
		}
		printf("%d\n",cnt);
	};
return 0;
}

