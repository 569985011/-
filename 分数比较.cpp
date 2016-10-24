#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N

//typedef struct {
//
//} ;


int main(){
long a1,b1,a2,b2;
scanf("%ld/%ld%ld/%ld",&a1,&b1,&a2,&b2) ;

printf("%ld/%ld",a1,b1);
if(a1*b2>a2*b1)
printf(" > ");
else if(a1*b2<a2*b1)
printf(" < ");
else printf(" = ");
printf("%ld/%ld",a2,b2); 






return 0;
}

