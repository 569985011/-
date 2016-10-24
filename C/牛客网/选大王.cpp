#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
//typedef struct {
//
//} ;


int main(){
    int n,m;int a[10001]={0};
 	while((scanf("%d%d",&n,&m))!=EOF){
 	
 	int cnt=0,t=n;int flag;
	for(int i=1;t>0;i++){
		if(i>n)i-=n;
		if(!a[i]){cnt++;
		}else continue;
		if(cnt%3==0)if(--t){
			a[i]=1;cnt=0;
			printf("%d ",i); 
		}else {
			printf("-%d-\n",i);break;
		}
		
	}
 };


return 0;
}

