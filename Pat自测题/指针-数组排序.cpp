#include<stdio.h>

#define N 10
int main(){
	int num[N];
	int*pai[N];
	for(int i=0;i<N;i++)scanf("%d",&num[i]);
	for(int i=0;i<N;i++)pai[i]=&num[i];
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(*pai[j]<*pai[i]){
				int*temp=pai[i];
				pai[i]=pai[j];
				pai[j]=temp;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(i)printf(",");printf("%d",*pai[i]);
	}
	return 0;
}
