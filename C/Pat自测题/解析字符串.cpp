#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10000

//typedef struct {
//
//} ;


int main(){
char a[N]={0};
char*flag;int i=0;
do{
	flag=fgets(&a[i++],1,stdin);
}while(flag!=NULL);
for(--i;i>=0;i--){
	printf("%c",a[i]);
}









return 0;
}

