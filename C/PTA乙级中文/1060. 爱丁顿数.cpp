#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100001

int cmp(const void*a,const void*b){
	int x=*(int*)a;
	int y=*(int*)b;
	return x-y;
}

int main(){
    int n;
	scanf("%d",&n);
int a[MaxSize];
for(int i=0;i<n;i++)scanf("%d",&a[i]);
qsort(a,n,sizeof(int),cmp);

int i;
for(i=n-1;i>0;i--){
//	printf("{%d-%d}",a[i],i);
	if(a[i]<n-i&&a[i+1]!=a[i])break;
}
printf("%d",a[i]);
	return 0;
}

