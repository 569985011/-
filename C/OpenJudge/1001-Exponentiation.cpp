#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************
*���ܣ����Լ���100����С����25���ڴη���Ҫ����߾���
*���ԣ�Openjudge1001
*˼·��ģ�±��Լ��㣬�ȸ�λ���˷��������С����Ӧ��������
*���ߣ�Chauncy523@gmail.com
*************************/


int main() {
	char temp[7];/*0.0<=R<=99.999*/
	int R[6];/*ֻ���ڼ�¼��λ�ϵ�����ע�⣺�ӵ�λ����λ*/
	int decimal;/*��¼С����λ��*/
	int power;/*�η� 1<=power<=25*/
	while(scanf("%s%d",temp,&power)==2) {

		for(int i=strlen(temp)-1,j=0;; i--) {
			if(i<0) {//�����λ���Ϊ-1. 
				R[j]=-1;
				break;
			}
			if(temp[i]=='.')decimal=strlen(temp)-i;
			else R[j++]=temp[i]-'0';
		}
		for(int i=0;R[i]!=-1;i++){
			printf("%d.",R[i]);
		} 
		printf("{%d}",decimal);
	}



	return 0;
}

