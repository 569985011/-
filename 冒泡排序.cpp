#include<stdio.h>

#define N 10000
int main() {
	int n,a[N],b[N];
	printf("Input n:");
	scanf("%d",&n);
	printf("Input %d numbers:",n);
	for(int i=0; i<n; i++)scanf("%d",&a[i]);

	for(int i=0; i<n; i++) {
		int j;
		for(j=i; j<n; j++) {
			if(a[j]<a[i]) {int min=a[j];
				for(int m=j;m>i;m--){
					a[m]=a[m-1];
				}
				a[i]=min;
			}


		}
	}
		printf("Sorting results:");
		for(int i=0; i<n; i++)printf("%4d",a[i]);
		return 0;
	}

