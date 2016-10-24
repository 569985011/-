#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000
/*

*/
//typedef struct {
//
//} ;
int char2int(char *a,int*b){
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	}
	int max=0;
	for(int i=1;i<10;i++)if(b[i]>b[max])max=i;
//	for(int i=0;i<10;i++)printf("%d-%d ",i,b[i]);
//	printf("b[max]=%d,",b[max]);
return b[max];
}

int main() {
	char a[N];

	while(gets(a)) {
		int b[10]={0};	
		int much=char2int(a,b);
		 for(int i=much;i;i--){
		 	for(int j=0;j<10;j++){
		 		if(b[j]>=i)printf("*");
		 		else printf(" ");
			 }printf("\n");
		 }
		 for(int i=0;i<10;i++)printf("%d",i);
		 printf("\n");
	};


	return 0;
}

