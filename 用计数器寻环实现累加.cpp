#include<stdio.h>

#define N
int main(){
int n;int cnt=0;
int sum=0;
do{
	printf("Input a number:\n");
	scanf("%d",&n);
	if(n>0){sum+=n;cnt++;}
	
}while(n);
printf("sum=%d,count=%d\n",sum,cnt);
return 0;
}

