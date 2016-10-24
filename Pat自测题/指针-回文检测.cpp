#include<stdio.h>
#include<string.h>
#define N 100
int main() {
	char a[N];
	int flag=0;
//	printf("Input string:");
	gets(a);//printf("**%s**",a);printf("%d\n",strlen(a));
	char*pStart=a;
	char*pEnd=NULL;
	pEnd=&a[strlen(a)-1];
	while(pStart<=pEnd) {
		if(*pStart!=*pEnd) {
			flag=1;
			break;
		}pStart++;pEnd--;
	}
	if(flag==1)printf("No\n");
	else printf("Yes\n");
	return 0;
}

