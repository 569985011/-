#include<stdio.h>
#include<stdlib.h>
#define N

int main(){
int n;int v,u;
scanf("%d",&n);
int*a=(int*)calloc(n+1,sizeof(int));
for(int i=0;i<n;i++){
	scanf("%d%d",&u,&v);
	/*注意输入的学校编号可能比n大！*/
	a[u]+=v;
}
int max=0,flag=0;
for(int i=0;i<n+1;i++){
	flag=1;
	if(a[i]>a[max])max=i;
}
if(flag)printf("%d %d",max,a[max]);
else printf("0");


return 0;
}

