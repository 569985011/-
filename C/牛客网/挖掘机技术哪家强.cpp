#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100001

//typedef struct {
//
//} ;


int main(){

int n;
scanf("%d",&n) ;
int a[N]={0};
if(n){

int num,score;int max=0;
for(int i=0;i<n;i++){
	scanf("%d%d",&num,&score);
	a[num-1]+=score;
	if(num>max)max=num;
}

int uax=0;
for(int i=1;i<=max;i++){
	if(a[i]>a[uax])uax=i;
}
printf("%d %d\n",uax+1,a[uax]);
}
else printf("0\n");





return 0;
}

