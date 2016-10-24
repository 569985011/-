#include<stdio.h>
#include<stdlib.h>
#define N
int main(){
int n,d;

scanf("%d",&n);
int score[101]={0};
for(int i=0;i<n;i++){
	scanf("%d",&d);
	score[d]++;
}
int k;
scanf("%d",&k);
int *b=(int*)malloc(k*sizeof(int));
for(int i=0;i<k;i++){
	scanf("%d",&b[i]);
	
}
for(int i=0;i<k;i++){
	if(i)printf(" ");
printf("%d",score[b[i]]);
}







return 0;
}

