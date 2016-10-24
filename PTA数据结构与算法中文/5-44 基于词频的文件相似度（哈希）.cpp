#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HashLenth 10007  //�����ڴ濪��3MB��Ҳ���ǲ���1MB�����ݸ����� 
/*���ܴ��ڵĿӡ����ȸ����ļ����ģ������һ����ֻ����һ���ַ�#���������ҵ�scan()�������ܲ����ˡ�
��ʱû�뵽��ô��֤������*/
/* ������
ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-08-30 18:26 	������ȷ 	26 	5-44 	gcc 	86 	2 	569985011
���Ե���
���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	18/18 	2 	1
���Ե�2 	����ȷ 	4/4 	2 	1
���Ե�3 	����ȷ 	2/2 	1 	1
���Ե�4 	����ȷ 	2/2 	1 	1
���Ե�5 	�𰸴��� 	0/4 	86 	2
�鿴����*/
typedef struct node *Node;
struct node {
	char*Word;
	int Reached[101];
	int Times;
};
Node Hash[HashLenth]= {0};
int Same[101][101]= {0};
int Sum[101]= {0};
int n;

int Mod(int);
char*scan();
void Insert(int ,char*);
int HashKey(char*);
void Refresh(Node,int);

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int flag=1;
		while(flag) {
			char*temp=scan();
			int len=strlen(temp);
			if(len==1&&temp[0]=='#')flag=0;
			else if(len>=3)Insert(i,temp);
		}
	}
	int m;
	if(scanf("%d",&m)==0)exit(1);
	while(m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(Same[a][b])printf("%.1f%%\n",Same[a][b]*100.0/(Sum[a]+Sum[b]-Same[a][b]));
		else printf("0.0%%\n");
	}
	return 0;
}

void Refresh(Node N,int h) {
	if(N->Reached[N->Times]==h)return;//ͬһ���ļ�������ֵ��ظ����ʲ��ۼ�
	++Sum[h];//�ļ��ʻ���+1
//	printf("[Used");
	N->Reached[++N->Times]=h;
	for(int i=0; i<N->Times; i++) {//���а������ַ������ļ��˴�Same++
//		printf("*");
		++Same[N->Reached[i]][h];
		++Same[h][N->Reached[i]];
	}
//	printf("]");
}

int HashKey(char*K) {//��������������
	int temp=(K[0]-'a')*32*32+(K[1]-'a')*32+K[2]-'a';
	temp*=HashLenth;
	temp/=27482;//26*32*32+26*32+26
	return temp;
}

int Mod(int Num) {
	while(Num<0)Num+=HashLenth;
	return Num%HashLenth;
}
void Insert(int h ,char*K) {
	int Key=HashKey(K);
	int flag;
	int i;
	for( i=0; i<=HashLenth/2; i++) {
		flag=Mod(Key+i*i);
		if(!Hash[flag])break;
		else if(!strcmp(Hash[flag]->Word,K)) {
			Refresh(Hash[flag],h);
			return ;
		}
		flag=Mod(Key-i*i);
		if(!Hash[flag])break;
		else if(!strcmp(Hash[flag]->Word,K)) {
			Refresh(Hash[flag],h);
			return ;
		}
	}
	if(i>HashLenth/2) {//ʵ��֤��ƽ̨�Ĵʻ���������
		exit(1);//	printf("ERROR:HashLenth is not enouth!\n");
	}
//	printf("[NEW]");
	++Sum[h];//�Ը��ļ��ʻ���+1
	Hash[flag]=(Node)malloc(sizeof(struct node));
	Hash[flag]->Word=(char*)malloc(sizeof(char)*strlen(K));
	strcpy(Hash[flag]->Word,K);
	Hash[flag]->Times=0;
	Hash[flag]->Reached[0]=h;
}

char*scan() {
	static char temp[11];
	static int Flag_br=1;
	int i=0;
	char c;
	do {
		c=getchar();
		if(c>='A'&&c<='Z') {
			if(i<10)temp[i++]=c-'A'+'a';
		} else if(c>='a'&&c<='z') {
			if(i<10)temp[i++]=c;
		} else if(!i&&Flag_br&&c=='#') {
			if((c=getchar())=='\n') {
				temp[i++]='#';
				Flag_br=1;
				break;
			} else {
				if(c>='A'&&c<='Z') {
					if(i<10)temp[i++]=c-'A'+'a';
				} else if(c>='a'&&c<='z') {
					if(i<10)temp[i++]=c;
				} else {
					Flag_br=0;
					break;
				}
			}
		} else if(c=='\n') {
			Flag_br=1;
			break;
		} else {
			Flag_br=0;
			break;
		}
	} while(1);
	temp[i]='\0';
//	printf("{%s}",temp);
	return temp;
}
