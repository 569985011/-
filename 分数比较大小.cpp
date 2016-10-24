#include<stdio.h>

#define N
int main(){
printf("Input two FENSHU:\n");
int a,A,b,B;
scanf("%d/%d,%d/%d",&a,&A,&b,&B);
if(a*B>b*A)printf("%d/%d>%d/%d\n",a,A,b,B);
else if(a*B==b*A)printf("%d/%d=%d/%d\n",a,A,b,B);
else printf("%d/%d<%d/%d\n",a,A,b,B);
return 0;
}

