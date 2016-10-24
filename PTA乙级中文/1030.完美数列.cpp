#include<stdio.h>
#include<stdlib.h>
#define N
void kuaipai(long*,int,int);

int main() {
	int  n;
	long p;
	scanf("%d%ld",&n,&p);
	long*a=(long*)malloc(n*sizeof(long));

	for(int i=0; i<n; i++) {
		scanf("%ld",&a[i]);
	}

	kuaipai(a,0,n-1);
	int much=1;//由于p为正整数，故任意数都能满足m<=m*p 
	for(int i=0; i<n; i++) {
		for(int j=i+much; j<n; j++) {//用最大长度迭代运算，加快进程 
			if(a[i]*p>=a[j])much++;
			else break;
		}
	}
	free(a);
	printf("%d",much);

	return 0;
}
void kuaipai(long*a,int low,int high) {//快速排序 
	int i=low;
	int j=high;
	long temp=a[i];
	if(low<high){
		while(i<j){
			while((a[j]>=temp)&&(i<j))j--; 
			a[i]=a[j];//找到第一个小于temp的数覆给low 
			while((a[i]<=temp)&&(i<j))i++;
			a[j]=a[i];//把从前往后第一个大于temp的值覆给后半段 
		}a[i]=temp;//把原来low 上的值送到恰当的位置 
		kuaipai(a,low,i-1);
		kuaipai(a,j+1,high);
	}else return;
}

