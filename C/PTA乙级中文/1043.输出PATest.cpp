#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10001
int main() {
	char a[N];
	gets(a);
	int b[6]= {0};
	for(int i=0; i<strlen(a); i++) {
		if(a[i]=='P')b[0]++;
		else if(a[i]=='A')b[1]++;
		else if(a[i]=='T')b[2]++;
		else if(a[i]=='e')b[3]++;
		else if(a[i]=='s')b[4]++;
		else if(a[i]=='t')b[5]++;
	}
	while(b[0]||b[1]||b[2]||b[3]||b[4]||b[5]) {
		if(b[0]>0) {
			printf("P");
			b[0]--;
		}
		if(b[1]>0) {
			printf("A");
			b[1]--;
		}
		if(b[2]>0) {
			printf("T");
			b[2]--;
		}
		if(b[3]>0) {
			printf("e");
			b[3]--;
		}
		if(b[4]>0) {
			printf("s");
			b[4]--;
		}
		if(b[5]>0) {
			printf("t");
			b[5]--;
		}

	}









	return 0;
}

