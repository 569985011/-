#include<stdio.h>
#include<string.h>
#define N 10000
int main() {
	char str[N];
	int len;
	int m,n;
	scanf("%s",str);
	scanf("%d%d",&m,&n);if(m<1&&n>1)m=1;if(m>1&&n<1)n=1;


	len=strlen(str);
	if(n<m) {
		int temp;
		temp=m;
		m=n;
		n=temp;
	}m--;n--;
	
	if(m>len-1||n<1) {
		printf("NULL");
	} else if(m<=len&&n>=len) {
		for(int i=m; i<=len; i++)printf("%c",str[i]);
	} else if(m==n) {
		printf("%c",str[m]);
	} else if(m<=n&&n<=len)for(int i=m; i<=n; i++)printf("%c",str[i]);

	return 0;
}

