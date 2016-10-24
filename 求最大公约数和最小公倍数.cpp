#include"stdio.h"
#include"stdlib.h"
#include<math.h>
long fib(int n){
	int f;
	if(n==0)f=0;
	else if(n==1)f=1;
	else f=fib(n-1)+fib(n-2);
	return f;
}
int main(){
	long c=0;
	for(int i=0;i<=20;i++){
		c+=fib(i)*fib(i);
		printf("n=%d,fib=%ld sum=%ld\n",i,fib(i),c);
	}
	
	
	

	return 0; 
} 

