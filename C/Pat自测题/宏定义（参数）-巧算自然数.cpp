#include<stdio.h>

#define N(a) ((a)/2)
#define U(a) ((a)*3+1)

int main(){
	int s;
	scanf("%d",&s);
	printf("%d",s);
	int cnt=1;
    while(s>1){
    	if(s%2==0)s=N(s);
    	else s=U(s);
    	
    	printf(",%d",s);
    	cnt++;
	}
	printf("\nstep=%d",cnt);

return 0;
}

