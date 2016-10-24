#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {

	
	int n;
	scanf("%d",&n);
	do {
		if((n-2)%4==0)printf("Yes\n");
		else printf("No\n");
	} while(scanf("%d",&n)!=EOF);
	return 0;
}

