#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 6//Ҫ�㹻������ʹ��MAXLENλ��m������ת��Ϊn���������λ�����ᳬ��MAXLEN 
//���ǣ����ڱ������ڽ��м����ʱ����ʹ��int���ʹ洢ÿ��Ƭ�ε�ֵ��
//���Ի���Ҫ�ϸ����MAXLEN�ĳ��ȣ����ܳ����������͵� ����

typedef struct charten {
	char a[MAXLEN]; //MAXLEN��ÿһ��n����������󳤶ȣ����Ի�ȡm��������ʱ����Ҫ
	struct charten*next;   //����ע���ȡ��m�������ĳ��ȣ���֤ת�������в���������
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
	int longest=Longest(m,n);//�����ȡʱ�ķֶγ���	
	while((c=getchar())!='\n') {
		if(i<longest)//��� m*MAXLENС��n ����ô������Ҳ��ʧЧ�ˡ����ԣ�MAXLEN�ں���Χ��Խ��Խ��
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
		//*1��else if...�˴����Ը���ʵ������������Ӹ����ַ���ֵ����
	}
	printf("\n...num=%lld\n",num);
	int i=0;
	while(num) {
		if(num%n<10)
			a[i++]=num%n+'0';
		else if(num%10<37)//26����д��ĸ
			a[i++]=num%n+'A'-10;
		//else if...���� *1������Ӧ����ֵ�Ķ���
		num/=n;
	}
	for(int j=0; j<i/2; j++) {
		char swap=a[j];
		a[j]=a[i-1-j];
		a[i-1-j]=swap;
	}
	for(int j=i; j<MAXLEN; j++) //�ѿ���ĸ�λ��Ϊ��
		a[j]='\0';
}
