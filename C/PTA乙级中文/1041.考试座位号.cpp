#include<stdio.h>
#include<stdlib.h>
#define N
struct zuohao {
	char a[15];
	int tryset;
	int result;
};
int main() {
	int n;
	scanf("%d",&n);

	struct zuohao*a=(struct zuohao*)malloc(n*sizeof(struct zuohao));

	for(int i=0; i<n; i++) {
		scanf("%s%d%d",&a[i].a,&a[i].tryset,&a[i].result);
	}
	int k;
	scanf("%d",&k);
	int*b=(int*)malloc(k*sizeof(int));
	for(int i=0;i<k; i++) {
		scanf("%d",&b[i]);
	}
	for(int i=0; i<k; i++) {
		for(int j=0; j<n; j++) {
			if(a[j].tryset==b[i]) {
				printf("%s %d\n",a[j].a,a[j].result);
				break;
			}
		}

	}






	return 0;
}

