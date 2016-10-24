#include<stdio.h>
#include<stdlib.h>
#define N
/*问题集中在int类型的key在进行若干次和运算后结果溢出，
本题限定n<=100000，但是key在峰值时达到1794917296*/
int main(){
int n;
scanf("%d",&n);
double num;double sum=0;
int cnt=n,key=n;
for(int i=0;i<n;i++){
scanf("%lf",&num);
	sum+=num*key;/*使用此代码，结果错误，运行时间也大得离谱*/ 
//for(long j=0;j<key;j++)
//	sum+=num;/*使用此代码运行超时*/
	cnt-=2;
		key+=cnt;
	
}
printf("%.2lf",sum);









return 0;
}

