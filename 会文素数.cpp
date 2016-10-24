#include<stdio.h>
#include<stdlib.h>
#define N
int isprime(int n){
	if(n<2)return 0;
	if(n==2||n==3)return 1;

	for(int i=2;i<n;i++){
		if(n%i==0)return 0;
	}return 1;
}
int main(){
printf("Input n:\n");
int n;scanf("%d",&n);
int cnt=0;
for(int i=10;i<n;i++){
	if(isprime(i)){
		int x=i;int y=0;
		while(x){
			y=y*10+x%10;
			x/=10;
		}
		if(y==i){
			printf("%4d",i);cnt++;
		}
	}
}
printf("\ncount=%d\n",cnt);
return 0;
}

