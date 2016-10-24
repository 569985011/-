#include<stdio.h>
#include<stdlib.h>
#define N

int main(){
int n;scanf("%d",&n);
int jia=0,yi=0,a,b,c,d;
for(int i=0;i<n;i++){
	scanf("%d%d%d%d",&b,&a,&d,&c);
		if(a!=c){
			if(b+d==a)yi++;
			if(b+d==c)jia++;
		}
	}
 printf("%d %d",jia,yi);
	










return 0;
}

