#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
�۷�Ѱ·
ʱ������ 1000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
nowcoder����ҵ��ʱ������һ���۷䣬��Ϊ�ռ�Ƚ�С���䷿ֻ�����ţ�����ͼ��ʾ��
(ͼ��  http://uploadfiles.nowcoder.com/images/20141114/51_1415949515175_1.jpg  )
����ֱ�ӷ���   http://www.nowcoder.com/pat/2/problem/257

�����������۷�ķ䷿���������Σ������۷�ֻ�����������������1�ŷ䷿������2�ź�3�ţ�
��6�ŷ䷿������7�ź�8�š���
�ָ��������䷿�ı��a��b��Ҫ�����䷿a���۷������䷿b�м�����ͬ·�ߡ�
ÿ�����������������������a��b��(0 < a < b < 2^31)          //int 
ÿ�������Ľ���������һ�С�������ݽ����Χ�� [0, 2^63)��  //long long
*/


int main(){

	
	/*���ڽ���ķ�Χ�ϴ󣬲���һһ�о٣��ʴ�
	��һ���ɿ���Χ���ṩһЩ���ý������Χ�������ʱ���м���*/
long long b[100];
b[0]=0;b[1]=1;b[2]=2;
b[3]=3;b[4]=5;
for(int i=5;i<100;i++){
	b[i]=b[i-1]+b[i-2];
}	
	//---------------------------------
	int n;
	scanf("%d",&n) ;
int*a=(int *)malloc(sizeof(int)*n);
int from,to;
for(int i=0;i<n;i++){
	scanf("%d%d",&from,&to);
	a[i]=to-from;
}

//printf("80-%lld,81-%lld,82-%lld\n",b[80],b[81],b[82]);
for(int i=0;i<n;i++){
	if(a[i]<100)printf("%lld\n",b[a[i]]);
	else {
		long long c=b[79],d=b[78],e;
		for(int j=100;j<=a[i];j++){
			e=d+c;
			d=c;c=e;
		}
		printf("%lld\n",e);
	}	
}



return 0;
}

