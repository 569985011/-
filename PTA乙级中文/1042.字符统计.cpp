#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1001
int main(){
char a[N];
gets(a);
int b[25]={0};
for(int i=0;i<strlen(a);i++){
	if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
	if(a[i]>='a'&&a[i]<='z')b[a[i]-97]++;
	
}
int max=0;
for(int i=0;i<25;i++){

	if(b[i]>b[max])
		max=i;
}
printf("%c %d",max+97,b[max]);

//printf("%s",a);








return 0;
}

