#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000
/*

*/
//typedef struct {
//
//} ;


int main() {
	char a[N];
	while(gets(a)) {
		for(int i=strlen(a)-1; i>0; i--) {
			if(a[i]==' ') {

				for(int j=i+1; a[j]!=' '&&a[j]!='\0'; j++)
					printf("%c",a[j]);
				printf(" ");
			}
		
		}
		for(int i=0;a[i]!=' '&&a[i]!='\0';i++){
			printf("%c",a[i]);
		}
		printf("\n");
	};


	return 0;
}

