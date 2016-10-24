#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 5
int main() {
	int a[N][N]= {0};
	for(int u=0; u<N; u++) {
		for(int v=0; v<N; v++) {
			scanf("%d",&a[u][v]);
		}
	}
	int sum=0,sum1=0;
	int flag=0;
	for(int i=0; i<N; i++)sum+=a[i][i]; //左梯之和
	for(int i=0; i<N; i++)sum1+=a[i][N-1-i]; //右梯求和
	if(sum==sum1) {
		for(int i=0; i<N; i++) {
			sum1=0;
			for(int j=0; j<N; j++) {
				sum1+=a[i][j];
			}
			if(sum1!=sum) {
				flag=1;
				break;
			}
		}
		
		for(int i=0; i<N; i++) {
			sum1=0;
			for(int j=0; j<N; j++) {
				sum1+=a[j][i];
			}
			if(sum1!=sum) {
				flag=1;
				break;
			}
		}
	}else flag=1;

		if(!flag) {
			printf("It is a magic square!\n");
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					printf("%4d",a[i][j]);
				}
				printf("\n");
			}
		}
		if(flag)printf("It is not a magic square!\n");
		return 0;
	}

