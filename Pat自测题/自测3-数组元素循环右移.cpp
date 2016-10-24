#include<stdio.h>

#define N 1000
int main() {
	int a[N]= {0};
	int n,m;
	scanf("%d %d",&n,&m);
	if(n>m){
		for(int i=m; i<n; i++)scanf("%d",&a[i]);
		for(int i=0;i<m;i++)scanf("%d",&a[i]);
	}else {
		for(int i=m%n;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<m%n;i++)scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",a[i]);
	}
	return 0;
}

