#include<stdio.h>
#include<stdlib.h>
#define N
int main(){
long c1,c2,time;
scanf("%ld%ld",&c1,&c2);
time=((c2-c1)%100>=50)?(c2-c1)/100+1:(c2-c1)/100;
//printf("\n-------------\n");
//printf("%ld\n",time);
int h,m,s;
h=time/3600;
m=time%3600/60;
s=time%3600%60;
printf("%02d:%02d:%02d",h,m,s);
return 0;
}

