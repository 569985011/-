#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
//typedef struct {
//
//} ;
char zhuan(int a){
	char c;
	switch(a){
		case 10:c='A';break;
		case 11:c='B';break;
		case 12:c='C';break;
		case 13:c='D';break;
		case 14:c='E';break;
		case 15:c='F';break;
		default:c=a+'0';break;
	}
	return c;
}

int main(){
    long long n;
	int r;
	char a[100];int i;
 	while((scanf("%lld%d",&n,&r))!=EOF){	
 	int num=0;
 	while(n){
 		num+=n%r;
 		n/=r;
	 }
	 i=0;
	while(num){
		a[i++]=zhuan(num%r);
		num/=r;
	}
	for(int j=i-1;j>=0;j--)printf("%c",a[j]);
	printf("\n");
 };


return 0;
}

