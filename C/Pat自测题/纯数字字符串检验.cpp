#include<stdio.h>
#include<string.h>

#define N 41
int IsAllDigit(char p[]);/*若全由数字组成，则函数返回1，否则返回0*/
int main(){
char a[N];
printf("Please input a string:\n");
gets(a);
if(IsAllDigit(a))printf("The string is a digit string.");
else printf("The string is not a digit string.");

return 0;
}
int IsAllDigit(char p[]){
	if(strlen(p)==0)return 0;
	for(int i=0;i<strlen(p)&&i<21;i++){
		if(p[i]<'0'||p[i]>'9')return 0;
	}
	return 1;
}
