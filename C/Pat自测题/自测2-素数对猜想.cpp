#include<stdio.h>
#include<math.h>
#define N
int isprime(int );
int main(){
int n,cnt=0;
scanf("%d",&n);
for(int i=2;i<=n;i++){
	if(isprime(i)&&isprime(i-2))cnt++;
}
printf("%d",cnt);
return 0;
}
int isprime(int i){
	if(i<2)return 0;
	else{
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0)return 0;
		}
	}
	return 1;
}
