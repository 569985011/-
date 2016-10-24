#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000
/*ÊäÈë a b c d e i k ; w
Êä³ö d w k ; i a b c e*/
int main(){
char a[N];
gets(a);
for(int i=0;i<strlen(a);i++){
	if(a[i]=='a')a[i]='d';
	else if(a[i]=='b')a[i]='w';
	else if(a[i]=='c')a[i]='k';
	else if(a[i]=='d')a[i]=';';
	else if(a[i]=='e')a[i]='i';
	else if(a[i]=='i')a[i]='a';
	else if(a[i]=='k')a[i]='b';
	else if(a[i]==';')a[i]='c';
	else if(a[i]=='w')a[i]='e';

}
printf("%s",a);
return 0;
}

