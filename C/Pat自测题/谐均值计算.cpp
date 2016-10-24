#include<stdio.h>

int main(){
printf("Input two doubles:\n");
double a,b,c;
scanf("%lf%lf",&a,&b); 
c=2*a*b/(a+b);
printf("1/((1/x+1/y)/2) = %0.3f\n",c);

return 0;
}

