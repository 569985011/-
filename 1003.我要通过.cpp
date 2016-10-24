#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N

/*题目给出了3个规则：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
虽然文字那么长，但是总结起来就是P之前的A数目乘以P与T之间的A的数目等于P后面的A的数目。
对于第1个规则：0*0=0。对于第2个规则：x*1=x。对于第3个规则：aPbTc如果正确，那么b一定是A、a=c,bA就是AA,a*2=aa=ca。*/
int judge(char*);

int main(){
int n;
scanf("%d",&n);
char a[10][101]={0};
for(int i=0;i<n;i++){
	scanf("%s",a[i]);
} 
	for(int i=0;i<n;i++){
	if(!judge(a[i]))printf("NO\n");
	else printf("YES\n"); 	
	}
return 0;
}

int judge(char *a){
	int flagp=-1,flaga=-1,flagt=-1;
	for(int i=0;i<strlen(a);i++){
		if(flagp!=-1)if(a[i]=='T'){flagt=i;break;}
		else if(a[i]!='A')return 0;
		if(flagp==-1&&a[i]=='P')flagp=i;
	}
	if(flagp==-1||flagt-flagp==1)return 0;
		
	for(int i=0;i<flagp;i++){
		if(a[i]!='A')return 0;
		if(a[i]!=a[strlen(a)-1-i])return 0;
	}
	
	for(int i=flagt+1;i<strlen(a)-1-flagp;i++){
		if(a[i]!='A')return 0;
	}
	if(flagp*(flagt-flagp-1)!=strlen(a)-flagt-1){
//	printf("%d-%d--%d",flagp,flagt,strlen(a)); 
	return 0;}
	
//	printf("P%d--T%d\n",flagp,flagt);
	
	return 1;
}
