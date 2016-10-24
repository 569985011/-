#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N
void zeng(int ,char*,int);
void jian(int ,char*,int);
int main(){
char zhengfu;//'+''-' 
int zhengshu;//只有一位 
char xiaoshu[10000]={0};//<=9999字节 
char zengjian;//'+''-'
int zhishu ;//<=9999; 
 
scanf("%c%d.%[^E]E%c%d",&zhengfu,&zhengshu,&xiaoshu,&zengjian,&zhishu);
//printf("%c**%d**%s**%c**%d**\n",zhengfu,zhengshu,xiaoshu,zengjian,zhishu);
if(zhengfu=='-')printf("-");

 
 if(zengjian=='+')zeng(zhengshu,xiaoshu,zhishu);
 else jian(zhengshu,xiaoshu,zhishu);
 
return 0;
}
void zeng(int zhengshu,char*xiaoshu,int zhishu){
	int flag=zhengshu;
	if(flag)printf("%d",zhengshu);
	for(int i=0;i<strlen(xiaoshu);i++){
		
		if(zhishu==0){if(!flag)printf("0");printf(".");
		}
		if(flag||xiaoshu[i]!='0'||zhishu<=0){
		flag=1;
		printf("%c",xiaoshu[i]);
		}
		zhishu--;
	}
	while(zhishu>0){
		printf("0");zhishu--;
	}
}
void jian(int zhengshu,char*xiaoshu,int zhishu){
	printf("0.");
	while(--zhishu>0){
		printf("0");
	}printf("%d%s",zhengshu,xiaoshu);
	
}
