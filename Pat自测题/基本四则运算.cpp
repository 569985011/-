#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 1000

int jisuan(int *,int,char*);
int add(int a,int b);
int jian(int a,int b);
int chen(int a,int b);
int chu(int a,int b);

int main() {
	int a[N];//´æ´¢ 
	char c[N];
	int t=0;
	scanf("%d%c",&a[t],&c[t]);
	int flag=1;
	while(flag) {
		t++;
		scanf("%d",&a[t]);
		flag=scanf("%c",c[t]);
	};
	static int end=t;
	/*0<=Êı×Ö<=t£¬0<=·ûºÅ<t*/
	int reusult=








	return 0;
}
int jisuan (int* a,int t,char *c) {
	if(c[t]=='*')jisuan(a[t],)
	
	return 0;
}
int add(int a,int b){
	return(a+b);
}
int jian(int a,int b){
	return(a-b);
}
int chen(int a,int b){
	return(a*b);
}
int chu(int a,int b){
	return(a/b);
}
