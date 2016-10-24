#include<stdio.h>

#define N
int main(){
long long a=0;
long long b=0;
long long ca=0;
long long cb=0;

int da=0,db=0;
scanf("%ld%d%ld%d",&a,&da,&b,&db);
while(a){
	if(a%10==da)ca=ca*10+a%10;
	a/=10;
}
while(b){
	if(b%10==db)cb=cb*10+b%10;
	b/=10;
}
printf("%ld",ca+cb);
return 0;
}

