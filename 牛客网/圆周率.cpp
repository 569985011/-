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
    int n,a,b;
 	while((scanf("%d%d%d",&a,&b,&n))!=EOF){
 	printf("%d",a/b);
 	if(n)printf("."); 
 	while(n--){
 		a=(a-a/b*b)*10;
 		printf("%d",a/b);
 		
	 }
 	printf("\n");

 };


return 0;
}

