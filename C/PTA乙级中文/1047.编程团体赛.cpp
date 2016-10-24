#include<stdio.h>
#include<stdlib.h>
#define N
typedef struct team{
int wu,yuan,score;}Team;
int main(){

int n;scanf("%d",&n);
int a[10001]={0},team,score;
while(n--){
	scanf("%d-%*d%d",&team,&score);
	a[team]+=score;
};int max=0;
for(int i=0;i<10000;i++){
	if(a[i]>a[max])max=i;
}
printf("%d %d",max,a[max]);








return 0;
}

