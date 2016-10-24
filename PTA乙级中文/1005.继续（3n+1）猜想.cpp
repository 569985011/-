#include<stdio.h>
#include<stdlib.h>
#define N
void fun(int ,int *);
int main() {
	int n;
	scanf("%d",&n);
	int k;
	int*a=(int *)calloc(101,sizeof(int));
	if(a==NULL) {
		printf("动态内存空间不足。异常退出");
		return 1;
	}

	for(int i=0; i<n; i++) {
		scanf("%d",&k);
		a[k]=1;
	}
	int min=0;
	int cnt=0 ;
	for(int i=1; i<101; i++) {
		if(a[i]) {

	
			fun(i,a);
		}
	}
	for(int i=101; i>0; i--) {
		if(a[i]) {
			if(cnt)printf(" ");
			printf("%d",i);		cnt++;
		}
	}

	free(a);
	return 0;
}
void fun(int n,int *a) {
	while(n!=1) {
		if(n%2==0) {
			n/=2;
			a[n]=0;
			//printf("n=%d,",n);
		} else {
			n=(n*3+1)/2;
			a[n]=0;
			//	printf("n=%d,",n);
		}
	}
//	printf("\n");
}
