#include<stdio.h>

#define N 10
int fun(int );
int main(){

printf("Result=%d",fun(N));
return 0;
}
int fun(int i){
	if(i==1)return 1;
	if(i==2)return 2;
	else return fun(i-1)+fun(i-2);
}
