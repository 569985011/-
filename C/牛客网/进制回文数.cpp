#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
//typedef struct {
//
//} ;
char zhuan(int a) {
	char c;
	switch(a) {
		case 10:
			c='A';
			break;
		case 11:
			c='B';
			break;
		case 12:
			c='C';
			break;
		case 13:
			c='D';
			break;
		case 14:
			c='E';
			break;
		case 15:
			c='F';
			break;
		default:
			c=a+'0';
			break;
	}
	return c;
}

int main() {
	int num;
	int r;
	char a[100];
	int i;
	while((scanf("%d",&num))!=EOF) {
		int flag=0;
		for(int r=2; r<17; r++) {
			int n=num;
			i=0;
			while(n) {
				a[i++]=zhuan(n%r);
				n/=r;
			}
			flag=0;
			for(int j=0; j<(i)/2; j++) {
				if(a[j]!=a[i-j-1]) {
					flag=1;
					break;
				}
			}
			if(!flag)break;
		}
		if(!flag) {
			printf("Yes\n");
		} else printf("No\n");

	};


	return 0;
}

