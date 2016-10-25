/*
������
ʱ�� 	��� 	�÷� 	��Ŀ 	���� 	��ʱ(ms) 	�ڴ�(kB) 	�û�
10��25�� 17:37 	����ȷ 	20 	1059 	C (gcc 4.7.2) 	10 	504 	����ţ��
���Ե�
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	2 	384 	12/12
1 	����ȷ 	10 	504 	3/3
2 	����ȷ 	8 	416 	3/3
3 	����ȷ 	3 	296 	2/2
�鿴����*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int IsPrim(int k) {
	if(k<4)return 1;
	if(k%2==0)return 0;
	for(int i=3; i<=sqrt(k); i+=2) {
		if(k%i==0)return 0;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d",&n);
	int a[10001]= {0};
	for(int i=0; i<n; i++) {
		int temp;
		scanf("%d",&temp);
		a[temp]=i+1;
	}
	int k;
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		int temp;
		scanf("%d",&temp);
		printf("%04d: ",temp);
		switch(a[temp]) {
			case 0:
				printf("Are you kidding?\n");
				break;
			case -1:
				printf("Checked\n");
				break;
			case 1:
				printf("Mystery Award\n");
				a[temp]=-1;
				break;
			default:
				if(IsPrim(a[temp]))printf("Minion\n");
				else printf("Chocolate\n");
				a[temp]=-1;
				break;
		}
	}

	return 0;
}

