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
	int much=1;//����pΪ������������������������m<=m*p 
	for(int i=0; i<n; i++) {
		for(int j=i+much; j<n; j++) {//����󳤶ȵ������㣬�ӿ���� 
			if(a[i]*p>=a[j])much++;
			else break;
		}
	}
	free(a);
	printf("%d",much);

	return 0;
}
void kuaipai(long*a,int low,int high) {//�������� 
	int i=low;
	int j=high;
	long temp=a[i];
	if(low<high){
		while(i<j){
			while((a[j]>=temp)&&(i<j))j--; 
			a[i]=a[j];//�ҵ���һ��С��temp��������low 
			while((a[i]<=temp)&&(i<j))i++;
			a[j]=a[i];//�Ѵ�ǰ�����һ������temp��ֵ�������� 
		}a[i]=temp;//��ԭ��low �ϵ�ֵ�͵�ǡ����λ�� 
		kuaipai(a,low,i-1);
		kuaipai(a,j+1,high);
	}else return;
}

