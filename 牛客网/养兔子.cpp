#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N

//typedef struct {
//
//} ;


int main(){

int n;
long long a[91];
a[0]=1;
a[1]=1;
a[2]=2;
int min=2;
while((scanf("%d",&n))!=EOF){
		if(n>min){
			for(int i=min+1;i<=n;i++){
				a[i]=a[i-1]+a[i-2];
			}
		}
		printf("%lld\n",a[n]);
	}







return 0;
}

