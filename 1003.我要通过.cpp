#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N

/*��Ŀ������3������
1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
��Ȼ������ô���������ܽ���������P֮ǰ��A��Ŀ����P��T֮���A����Ŀ����P�����A����Ŀ��
���ڵ�1������0*0=0�����ڵ�2������x*1=x�����ڵ�3������aPbTc�����ȷ����ôbһ����A��a=c,bA����AA,a*2=aa=ca��*/
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
