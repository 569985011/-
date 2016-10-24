#include<stdio.h>

#define N 10
int main() {
	printf("Input n (n<=10):\n");
	int n;
	scanf("%d",&n);
	int a[N][N]= {1};
	for(int i=1; i<n; i++)a[i][0]=1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<i+1; j++) {
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
			printf("%4d",a[i][j]);
		}printf("\n");
	}
	return 0;
}

