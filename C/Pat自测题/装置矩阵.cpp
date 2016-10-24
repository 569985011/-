#include<stdio.h>

#define N 100
#define M 100

int main(){
int a[N+M][M+N]={0};
int temp=1;
int n;
scanf("%d",&n);
for(int u=0;u<=n;u++){
	for(int v=0;v<=n;v++){
	a[u][v]=temp++;
	}temp--;
}

	printf("The original matrix is:\n");
for(int u=0;u<n;u++){
	for(int v=0;v<n;v++){
		printf("%3d",a[u][v]);
	}printf("\n");
}
//----------------------
for(int u=0;u<n;u++){
	for(int v=u;v<n;v++){
		temp=a[u][v];
		a[u][v]=a[v][u];
		a[v][u]=temp;
	}
}
printf("The changed matrix is:\n");
for(int u=0;u<n;u++){
	for(int v=0;v<n;v++){
		printf("%3d",a[u][v]);
	}printf("\n");
}

return 0;
}

