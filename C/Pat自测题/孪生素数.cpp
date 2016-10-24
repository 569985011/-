#include<stdio.h>
#include<stdlib.h>
#define N
int isprime(long n){
	if(n<2)return 0;
	if(n==2||n==3)return 1;

	for(int i=2;i<n;i++){
		if(n%i==0)return 0;
	}return 1;
}
int main(){
printf("please input c,d(c>2):\n");
long  c,d;int total=0;
scanf("%ld%*c%ld",&c,&d);
//if(d<c){
//	long temp=d;
//	d=c;c=temp;
//	
//}
for(long i=c;i<=d-2;i++){

	if(isprime(i)&&isprime(i+2))
	{printf("(%ld,%ld)\n",i,i+2);
	total++;}

}
printf("total=%d\n",total);
return 0;
}

