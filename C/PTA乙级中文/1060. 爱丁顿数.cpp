/*
WRONG !Wait for Check.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100001

int cmp(const void*a,const void*b) {
	int x=*(int*)a;
	int y=*(int*)b;
	return y-x;
}

int main() {
	int n;
	scanf("%d",&n);
	int a[MaxSize];
	for(int i=0; i<n; i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);

	int i;
	for(i=0; a[i]>i&&i<n; i++) {
//		printf("{%d-%d}",a[i],i);
		
	}
	
	if(i==n)printf("%d",n);
	else if(a[i]==i) {
		if(a[i-1]!=a[i])printf("%d",i);
			else printf("%d",i-1);
	} else	printf("%d",a[i]);
	return 0;
}

