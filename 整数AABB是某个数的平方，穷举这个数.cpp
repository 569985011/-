#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){

int k,m,n,i,j;
int flag=1;
for(m=31;flag;m++){
    k=m*m;
	i=k/100;
	j=k%100;
	if(i/10==i%10&&j/10==j%10)break;
}
printf("k=%d,m=%d\n",k,m);
return 0;
}

