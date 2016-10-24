#include<stdio.h>

#define N
int eachsum(int,int*);
int main(){
int num;int sum=0;
scanf("%d",&num);
printf("%d",eachsum(num,&sum));

return 0;
}
int eachsum(int num,int *sum){
	if(num==0)return *sum;
	else {*sum+=num%10;num/=10;
	eachsum(num,sum);
		}
}
