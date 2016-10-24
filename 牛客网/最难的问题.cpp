#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000
/*

*/

int main() {
	char a[N];
	while(gets(a)) {
		for(int i=0; i<strlen(a); i++) {
			if(a[i]>='F'&&a[i]<='Z')
			printf("%c",a[i]-5);
			else  
			{
				switch(a[i]) { 
					case 'A':
						printf("V");
						break;
					case 'B':
						printf("W");
						break;
					case 'C':
						printf("X");
						break;
					case 'D':
						printf("Y");
						break;
					case 'E':
						printf("Z");
						break;
					default:printf("%c",a[i]);
						break;
				}
			}

		}
printf("\n");
	};


	return 0;
}

