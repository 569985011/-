#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int CountDigit(int number,int digit);
int main(){
printf("Input m,n:\n");
int m,n;
scanf("%d,%d",&m,&n);
printf("%d\n",CountDigit(m,n));
return 0;
}
int CountDigit(int number,int digit){
	int cnt=0;
	while(number){
		if(number%10==digit)cnt++;
		number/=10;
	}
	return cnt;
}
