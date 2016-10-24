 #include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N


int main(){
    int n;
 	scanf("%d",&n);
 	float inch,foot;
 	foot=n/100.0/0.3048;
 	inch=foot-foot/12*12;
 	foot/=12;
 	printf("%f %f",foot,inch);
 	

 


return 0;
}

