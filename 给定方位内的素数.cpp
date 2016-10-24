#include<stdio.h>

#define N
int isprime(int n){
	if(n<2)return 0;else if(n==2||n==3)return 1;
	
	for(int i=2;i<n;i++){
		if(n%i==0)return 0;
	}return 1;
}
int main(){
int m,n;int cnt=0;
scanf("%d%d",&m,&n);
for(int i=m;i<=n;i++){
	if(i==m&&m!=n)continue;
	if (isprime(i)){if(cnt)printf(" ");
	printf("%d",i);cnt++;}
}if(!cnt)printf("NULL");

return 0;
}

