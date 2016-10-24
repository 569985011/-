#include<stdio.h>
#include<stdlib.h>
#define N
int main(){
printf("Input m, n:\n");
int m,n;scanf("%d%*c%d",&m,&n);
int s=0,y=0;
for(int i=1;i<m;i++){
	if(m%i==0)
	s+=i;
}
for(int i=1;i<n;i++){
	if(n%i==0)y+=i;
}
if(s==n&&y==m){
	printf("Yes!\n");

}else printf("No!\n");


return 0;
}

