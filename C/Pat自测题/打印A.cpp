#include<stdio.h>

#define N
int main() {
	int n;
	int mid;char c='*';
	scanf("%d",&n);
	if(n%2==0)mid=n/2;
	else mid=(n+1)/2;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<n-i; j++)printf(" ");
	printf("*");
		if(i==mid) {
			for(int j=0; j<i*2-2; j++)printf("*");
		} else if(i>1) {
			for(int j=0; j<i*2-3; j++)printf(" ");
			printf("*");
		}
	printf("\n");
	}

	return 0;
}

