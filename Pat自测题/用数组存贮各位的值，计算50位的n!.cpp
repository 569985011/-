#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 50
#define N 80
int main() {
	int a[M][N];
	for(int v=0; v<M; v++)
		for(int u=0; u<N; u++)a[v][u]=-1;//用负1来标识空位
	int n;//阶乘n！
	a[1][0]=1;//初始化1！
printf("Input n:");
	scanf("%d",&n);


	for(int i=2; i<=n; i++) {
		int carry=0;//进位
		int j;
		for(j=0; a[i-1][j]!=-1; j++) {

			a[i][j]=i*a[i-1][j]+carry;
			carry=0;
			if(a[i][j]>9) {
				carry=a[i][j]/10;
				a[i][j]%=10;

			}

		}

		for(;a[i-1][j]==-1&& carry>0; j++) {
			a[i][j]=carry%10;
			carry/=10;
		}

	}

	for(int v=1; v<=n; v++) {
		if(a[v][0]!=-1) {
			printf("%d! = ",v);
			for(int u=N-1; u>=0; u--)
				if(a[v][u]!=-1)printf("%d",a[v][u]);
			printf("\n");
		}
	}

	return 0;
}

