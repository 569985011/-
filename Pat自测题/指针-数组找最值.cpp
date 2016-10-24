#include<stdio.h>

#define N 10
void InputArray(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main(){
printf("Input m,n:\n");
int m,n;int a[N][N]={0};
int pRow,pCol;int *p=&a[0][0];
scanf("%d,%d",&m,&n);
InputArray(p,m,n);
FindMax(p,m,n,&pRow,&pCol);

return 0;
}
void InputArray(int *p, int m, int n){
	printf("Input %d*%d array:\n");
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
scanf("%d",p+i*n+j);
}
int  FindMax(int *p, int m, int n, int *pRow, int *pCol){
int*max=p;
for(int i=0;i<m;i++)
for(int j=0;j<n;j++){
	if(*(p+i*n+j)>*max){
		max=p+i*n+j;
		*pRow=i;
		*pCol=j;
	}
}
printf("max=%d,row=%d,col=%d\n",*max,*pRow,*pCol);
}
