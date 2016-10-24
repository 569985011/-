#include<stdio.h>

#define N
int main(){
	int a1,a=0,b=0,wei=0,k;
	scanf("%d",&a);
	a1=a;
while(a){
	for(int i=0;i<wei;i++){
            b+=2;
		}
 wei++;
	k=a%10;
	if(k%2==wei%2){
		b+=1;
	}
	a/=10;
}
printf("%d",&b);
return 0;
}

