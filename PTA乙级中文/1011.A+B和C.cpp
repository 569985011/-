#include<stdio.h>
#include<stdlib.h>
#define N
int main(){
long long a,b,c;
int n;
scanf("%d",&n);
int*k=(int*)calloc(n,sizeof(int));
for(int i=0;i<n;i++){
	scanf("%ld%ld%ld",&a,&b,&c);

	k[i]=(a+b)>c?1:0;
}
for(int i=0;i<n;i++){
	if(k[i])printf("Case #%d: true\n",i+1);
	else printf("Case #%d: false\n",i+1);
}
return 0;
}

