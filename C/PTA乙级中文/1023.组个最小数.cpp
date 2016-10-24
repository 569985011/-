#include<stdio.h>

#define N
int main() {
	int a[10]= {0};
	for(int i=0; i<10; i++) {
		scanf("%d",&a[i]);
	}
	if(a[0]==0) {
		for(int i=1; i<10; i++) {
			for(int j=0; j<a[i]; j++) {
				printf("%c",i+'0');
			}
		}
	} else {
		int i;
		for( i=1; i<10; i++) {
			if(a[i]!=0)break;
		}
		a[i]-=1;
		printf("%c",i+'0');
		for(int j=0; j<10; j++) {
			for(int m=0; m<a[j]; m++) {
				printf("%c",j+'0');
			}
		}
	}
	return 0;
}

