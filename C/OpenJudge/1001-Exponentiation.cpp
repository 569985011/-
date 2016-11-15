#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************
*功能：笔试计算100以内小数的25以内次方。要求最高精度
*来自：Openjudge1001
*思路：模仿笔试计算，先各位做乘法，最后数小数点应该在哪里
*作者：Chauncy523@gmail.com
*************************/


int main() {
	char temp[7];/*0.0<=R<=99.999*/
	int R[6];/*只用于记录个位上的数，注意：从低位到高位*/
	int decimal;/*记录小数点位数*/
	int power;/*次方 1<=power<=25*/
	while(scanf("%s%d",temp,&power)==2) {

		for(int i=strlen(temp)-1,j=0;; i--) {
			if(i<0) {//对最高位标记为-1. 
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

