#include<stdio.h>
unsigned int ComputeAge(unsigned int );
unsigned int ComputeAge(unsigned int n){
	if(n==1)return 10;
	else return ComputeAge(n-1)+2;
} 
int main(){

	unsigned int x=0,y;
	scanf("%u",&x);
	y=ComputeAge(x);
	printf("The person's age is %u\n",y);
	return 0;
}

