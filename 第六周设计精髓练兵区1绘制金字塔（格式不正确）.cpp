#include<stdio.h>
int main() {
	printf("Please input a capital:\n");
	char word;
	int num=0;
	scanf("%c",&word);
	char c;
	num=word-'A'+1;
	int cnt;
	cnt=num-1;
	for(int i=1; i<num+1; i++) {
		c='A'-1;
		for(int k=num-i; k>0; k--)printf(" ");
		for(int j=0; j<i*2-1; j++) {
			if(j<i)printf("%c",++c);
			else printf("%c",--c);
		}
		if(cnt--)printf("\n");
	}

	return 0;
}
