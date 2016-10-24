#include<stdio.h>
#include<string.h>
#define N 100
//5是限制输入的字符串数量
int main() {
	char a[5][N];
	char* p[5];char*change=NULL;
	for(int i=0; i<5; i++)p[i]=a[i];
	printf("Input five countries' names:\n");
	for(int i=0; i<5; i++)
		gets(a[i]);
	
	for(int i=0; i<5; i++) {
		int min=i;
		for(int j=min+1; j<5; j++) {
			if(strcmp(p[j],p[min])<0){
				change=p[j];
				p[j]=p[min];
				p[min]=change;

			}
			}
	}
	printf("The minimum is:%s\n",p[0]);
	return 0;
}

