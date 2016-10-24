#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1001

int IsContains(char *a,char* b){
	int cnt=0,flag;
	for(int i=0;i<strlen(b);i++){
		flag=0;
		for(int j=0;j<strlen(a);j++){
			if(a[j]==b[i]){
				flag=1;a[j]='*';break;
			}
			}
			if(!flag)cnt++;
	}
	return cnt;
}
int main(){
char a[N],b[N];
gets(a);
gets(b);
int i=IsContains(a,b);
if(!i)printf("Yes %d",(strlen(a)-strlen(b)));
else printf("No %d",i);


return 0;
}

