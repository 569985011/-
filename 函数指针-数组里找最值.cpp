#include<stdio.h>

#define N 10
int FindMax(int num[], int n, int *pMaxPos);//函\
数返回最大值，pMaxPos返回最大值所在的下标
int FindMin(int num[], int n, int *pMinPos);//函\
数返回最小值，pMaxPos返回最小值所在的下标
int main(){
int num[N]={0};
int *Max=num,*Min=num;
printf("Input 10 numbers:\n");
for(int i=0;i<N;i++){
	scanf("%d",&num[i]);
	Max=&num[FindMax(num,i,Max)];//printf("max=%d i=%d",*Max,i);
	Min=&num[FindMin(num,i,Min)];//printf(" min=%d",*Min);
}
printf("Max=%d,Position=%d,",*Max,Max-num);
printf("Min=%d,Position=%d\n",*Min,Min-num);
return 0;
}
int FindMax(int num[], int n, int *pMaxPos){
	if(num[n]>*pMaxPos)return n;
	else return pMaxPos-num;
}
int FindMin(int num[], int n, int *pMinPos){
	if(num[n]<*pMinPos)return n;
	else return pMinPos-num;
}
