#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 6//要足够长，以使得MAXLEN位的m进制数转化为n进制数后的位数不会超过MAXLEN 
//但是，由于本程序在进行计算的时候是使用int类型存储每个片段的值，
//所以还是要严格控制MAXLEN的长度，不能超过ｉｎｔ类型的 极限

typedef struct charten {
	char a[MAXLEN]; //MAXLEN是每一段n进制数的最大长度，所以获取m进制数的时候需要
	struct charten*next;   //格外注意截取的m进制数的长度，保证转换过程中不会产生溢出
} CHAR;

void MtoN(char*,int ,int,int);
int Longest(int m,int n);
int main() {
	int m;
	int n;
	CHAR* head=(CHAR*)malloc(sizeof(CHAR));
	CHAR*a=head;
//	printf("longest-%d\n",Longest(2,36));
//	printf("longest-%d\n",Longest(36,2));
	scanf("%d%d ",&m,&n);
	char c;
	int i=0;
	int longest=Longest(m,n);//计算读取时的分段长度	
	while((c=getchar())!='\n') {
		if(i<longest)//如果 m*MAXLEN小于n ，那么本程序也就失效了。所以，MAXLEN在合理范围内越大越好
			a->a[i]=c;
		else {
//		printf("%s**",a->a);
			i=0;
			a->next=(CHAR*)malloc(sizeof(CHAR));
			a->next->a[i]=c;
			{MtoN(a->a,m,n,longest);printf("TEXT1");
			}
//			printf("%s",a->a);
			a=a->next;
		}
		i++;
//		printf("%c",c);
	};
	{MtoN(a->a,m,n,longest);printf("TEXT2");
			}
	a->next=NULL;
	a=head;
	printf("\n-----------------\n");
while(a!=NULL){
	for(int f=0;f<MAXLEN;f++)
	printf("%c-",a->a[f]);
	printf("\n");
	a=a->next;
}
	return 0;
}
int Longest(int m,int n){
	if(m<=n)return MAXLEN;
	int num=1;
	for(int i=1;i<MAXLEN;i++){
		num*=n;
	}
	int cnt=0;
	while(num){
		num/=m;cnt++;
	};
//	printf("cnt=%d",cnt);
	return cnt;
}
void MtoN(char *a,int m,int n,int longest) {
	long long num=0;
	for(int i=0; i<longest; i++) {
		printf("%c+",a[i]);
		if(a[i]>='0'&&a[i]<='9')num=num*m+a[i]-'0';
		else if(a[i]>='A'&&a[i]<='Z')num=num*m+a[i]-'A'+10;
		//*1：else if...此处可以根据实际情况进行增加各种字符的值定义
	}
	printf("\n...num=%lld\n",num);
	int i=0;
	while(num) {
		if(num%n<10)
			a[i++]=num%n+'0';
		else if(num%10<37)//26个大写字母
			a[i++]=num%n+'A'-10;
		//else if...根据 *1：处相应增补值的定义
		num/=n;
	}
	for(int j=0; j<i/2; j++) {
		char swap=a[j];
		a[j]=a[i-1-j];
		a[i-1-j]=swap;
	}
	for(int j=i; j<MAXLEN; j++) //把空余的高位置为零
		a[j]='\0';
}
