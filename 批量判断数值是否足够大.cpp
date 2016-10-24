#include<stdio.h>
#define N 10
int isenough(int parameter,int reference);
int main() {
	int a[N]= {0};
	int cnt=0;
	int reference;//参照物
	int parameter;//参数
	for(int i=0; i<N; i++)scanf("%d",&a[i]);
	scanf(" %d",&reference);
	for(int i=0; i<N; i++) {
		if(isenough(a[i],reference))cnt++;
	}
	printf("%d",cnt);
	return 0;
}
int isenough(int parameter,int reference) {
	if(parameter<=reference+30  //这个30是外挂，注意删减
	  )return 1;
	else return 0;
}
