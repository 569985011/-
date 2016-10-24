#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N
int isprime(double n){
	if(n<2)return 0;
	if(n==2||n==3)return 1;

	for(int i=2;i<=sqrt(n);i++){
		if(n/i==(int)(n/i))return 0;
	}return 1;
}
int main(){
printf("Input n:\n");
int n;scanf("%d",&n);
double s;int cnt=0;
for(int i=2;i<=n;i++){
	s=2;
	for(int j=1;j<i;j++){
		s*=2;
	}
	if(isprime(s-1)){
	printf( "2^%d-1=%.0lf\n",i,s-1);
	cnt++;}
}printf("count=%d\n",cnt);

return 0;
}

