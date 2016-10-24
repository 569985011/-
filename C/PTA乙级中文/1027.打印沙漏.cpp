#include<stdio.h>

#define N
int sum(int);
int main(){
int num;char c;int i;
scanf("%d %c",&num,&c);
for(i=0;sum(i)<=num;i++);i--;
//printf("%d\n",i);
{
	for(int j=0;j<i;j++){
		for(int v=0;v<j;v++)printf(" ");
		for(int v=0;v<i*2-1-j*2;v++)printf("%c",c);
		printf("\n");
	}
	for(int j=1;j<i;j++){
		for(int v=1;v<i-j;v++)printf(" ");
		for(int v=0;v<j*2+1;v++)printf("%c",c);
		printf("\n");
	}
}
printf("%d",num-sum(i));
return 0;
}
int sum(int i){
	if(i==0)return 0;
	else if(i==1)return 1;
	else return 4*i-2+sum(i-1);
}
