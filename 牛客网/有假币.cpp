#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
//typedef struct {
//
//} ;


int main(){
    long long n;int cnt;
   
//	printf("%lld",a[30]);
 	while((scanf("%lld",&n))!=EOF){
 	if(n==0)break;
 		cnt=0;
 		while(n>=2){
 			if(n%3)n=n/3+1;else n/=3;
			 cnt++;
		 }
printf("%d\n",cnt);
 };


return 0;
}

