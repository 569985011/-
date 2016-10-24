#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10001
/*

*/
//typedef struct {
//
//} ;


int main() {
	char a[N],b[N];
	while((scanf("%s%s",a,b))!=EOF) {
			int flag=0;
		for(int i=0; i<strlen(b); i++) {
			
			for(int j=0; j<strlen(a); j++) {
				if(a[j]==b[i]) {
					b[i]=1;
					break;
				}
			}
			if(b[i]!=1) {
				flag=1;
				break;
			}
		}
		if(flag)printf("No\n");
		else printf("Yes\n");
};


return 0;
}

