#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N
/*NowCoder小定律
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<50),
判定该表达式的值是否为素数 

*/
//typedef struct {
//
//} ;
int isprime(int a){
	if(a<2)return 0;
	if(a==2|a==3)return 1;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)return 0;
	}
	return 1;
}

int main(){
    int x,y;
    int a[91];	 int b[91];
    a[40]=41;a[39]=41;
//			 a[41]=43;a[38]=43;
//   		 a[42]=47;a[37]=47;
//			 a[43]=53;a[36]=53;	
//			 a[44]=61;

	 b[40]=1;b[39]=1;
//	 		 b[41]=1;b[38]=1;
//	 		 b[42]=1;b[37]=1;
//	 		 b[43]=1;b[36]=1;
//	 		 b[44]=1;
	 		 
    for(int i=1;i<50;i++){
    	a[i+40]=a[i+39]+i*2;
    	b[i+40]=isprime(a[i+40]);
    	if(i<40){
    		a[39-i]=a[i+40];
    		b[39-i]=b[i+40];
		}
    
    
	}

//    for(int i=1;i<91;i++){
//    	printf("%d-%lld-%d  ",i-40,a[i],b[i]);
//	}
//	
    while((scanf("%d%d",&x,&y))){
    	if(x==0&&y==0)break;
    	int flag=0;
    	for(int i=x+40;i<=y+40;i++){
    		if(!b[i]){flag=1;break;
			}
		}if(flag)printf("Sorry\n");else printf("OK\n");
	}









return 0;
}

