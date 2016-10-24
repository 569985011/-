#include<stdio.h>
#include<stdlib.h>
#define N
int main() {
	printf("Input array size:\n");
	int n;
	int*a;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*(n+1));
	if(a==NULL) {
		printf("ÄÚ´æ²»×ã");
		exit(0);
	}
	printf("Input array:\n");
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i])
		;
	}
	printf("Input x:\n");
	int x;
	scanf("%d",&x);
	for(int i=0; i<n; i++) {
		if(a[i]<=x&&a[i+1]>=x) {
			for(int j=n; j>i+1; j--) {
				a[j]=a[j-1];
			}a[i+1]=x;break;
			
		}
	}
	printf("After insert %d:\n",x);
	for(int i=0; i<n+1; i++)printf("%4d",a[i]);
	return 0;
}

