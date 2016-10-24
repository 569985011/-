#include<stdio.h>

#define N
int main(){
const char *month[13]={"Illegal month","January","February",
"March","April","May","June","July","August",
"September","October","November","December"};
int n;
printf("Input month number:\n");
scanf("%d",&n);
if(n>0&&n<13)printf("month %d is %s\n",n,month[n]);
else printf("%s\n",month[0]);
return 0;
}

