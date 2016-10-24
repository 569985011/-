#include<stdio.h>
#include<stdlib.h>
#define N
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int*a=(int *)calloc(n,sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d",&a[(i+m)%n]);
	}
	int cnt=0;
	for(int i=0; i<n; i++) {
		if(cnt)printf(" ");
		printf("%d",a[i]);
		cnt++;
	}
	return 0;
}

