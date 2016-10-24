/*
*对于一个长度为100000 的字符串寻找最长子串 
*
*
*/
#include<stdio.h>
typedef struct Str{
	char a[100001];
	struct Str* next;
	struct Str* left;
}STR;
int main(){
//	char str[100001];
//	gets(str);
//	char same[50001];//子串长度最大只为母串的一半 
//	STR* a=(STR*)malloc(sizeof(STR));
//	a->left=str;
//	
//	for(int i=1;i<strlen(str);i++){
//		a->next=(STR*)malloc(sizeof(STR));
//		a->a=&str[1];
//	}


	char str[20]="nihao!";
	char a[20];
	a=str[1];
	printf("%s",a);
	return 0; 
} 
