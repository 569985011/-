#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#define N 10000 
int main()
{
		int num;
	scanf("%d",&num);
		char m[N][21]={0};
	for(int i=0;i<num;i++){
		scanf("%s",m[i]);
	}
	for(int i=0;i<num;i++){
			int v=strlen(m[i]);
		if(v<6)printf("Not Safe\n");//长度限制 
		else{
			int cnt0=0;int cnt1=0;int cnt3=0;int cnt2=0;
			for(int j=0;j<21;j++){
				if(m[i][j]>='0'&&m[i][j]<='9')cnt0=1;//数字 
				else if(m[i][j]>='A'&&m[i][j]<='Z')cnt1=1;//大写字母 
				else if(m[i][j]>='a'&&m[i][j]<='z')cnt2=1;//小写 
				else if(m[i][j]!=0)cnt3=1;//其他符合（不含结束符） 
				if((cnt0+cnt1+cnt2+cnt3)==3)break;
			}int cnt;cnt=cnt0+cnt1+cnt2+cnt3;
			//printf("cnt  %d %d %d %d",cnt0,cnt1,cnt2,cnt3);
			switch(cnt){
				case 0:case 1:printf("Not Safe\n");break;
				case 2:printf("Medium Safe\n");break;
				default:printf("Safe\n");break;
			}
		}
	}
	return 0;
} 
