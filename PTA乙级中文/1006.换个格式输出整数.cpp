#include<stdio.h>

#define N
int main(){
int num;
scanf("%d",&num);
for(int i=0;i<num/100;i++){
	printf("B");
}
for(int i=0;i<num/10%10;i++){
	printf("S");
}
for(int i=1;i<=num%10;i++){
	printf("%d",i);
}
return 0;
}

