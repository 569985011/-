#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
int main(){
printf("Input a string:\n");
char a[N];
gets(a);
for(int i=0;i<strlen(a);i++){
	for(int j=i+1;j<strlen(a);j++){
		if(a[i]>a[j]){
			char c=a[i];
			a[i]=a[j];
			a[j]=c;
		}
	}
}
printf("%s",a);

return 0;
}

