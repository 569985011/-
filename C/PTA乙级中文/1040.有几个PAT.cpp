#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000
/*����Ӧ�õ�������ÿ����һ��T�ͷ�����
������һ��A���͵���
������P,�͵���
�Ӷ�ʵ�ֿ�ݼ���*/

int main(){
char a[N]={0};
gets(a);
long long cntt=0,cntat=0,cntpat=0;
int lefti=0,flagp=0; 
for(int i=strlen(a)-1;i>=0;i--){
	if(a[i]=='T')
		cntt++;
		else if(a[i]=='A')
		cntat=(cntat+cntt)%1000000007;
		else if(a[i]=='P')
		cntpat=(cntpat+cntat)%1000000007;
	
	
} 
printf("%lld",cntpat);


return 0;
}

