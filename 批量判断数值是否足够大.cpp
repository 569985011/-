#include<stdio.h>
#define N 10
int isenough(int parameter,int reference);
int main() {
	int a[N]= {0};
	int cnt=0;
	int reference;//������
	int parameter;//����
	for(int i=0; i<N; i++)scanf("%d",&a[i]);
	scanf(" %d",&reference);
	for(int i=0; i<N; i++) {
		if(isenough(a[i],reference))cnt++;
	}
	printf("%d",cnt);
	return 0;
}
int isenough(int parameter,int reference) {
	if(parameter<=reference+30  //���30����ң�ע��ɾ��
	  )return 1;
	else return 0;
}
