#include<stdio.h>
#include<stdlib.h>
#define N
/*���⼯����int���͵�key�ڽ������ɴκ�������������
�����޶�n<=100000������key�ڷ�ֵʱ�ﵽ1794917296*/
int main(){
int n;
scanf("%d",&n);
double num;double sum=0;
int cnt=n,key=n;
for(int i=0;i<n;i++){
scanf("%lf",&num);
	sum+=num*key;/*ʹ�ô˴��룬�����������ʱ��Ҳ�������*/ 
//for(long j=0;j<key;j++)
//	sum+=num;/*ʹ�ô˴������г�ʱ*/
	cnt-=2;
		key+=cnt;
	
}
printf("%.2lf",sum);









return 0;
}

