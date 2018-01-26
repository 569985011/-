#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HashLenth 10007  //�����ڴ濪��3MB��Ҳ���ǲ���1MB�����ݸ����� 

/* ������
�ύʱ��	״̬	����	��Ŀ	������	��ʱ	�û�
2018/1/26 17:49:32	����ȷ	30	7-44	C (gcc)	75 ms	569985011
���Ե�	��ʾ	���	��ʱ	�ڴ�
0	sample	����ȷ	2 ms	244KB
1	ͬһ�ļ����ظ����ֵĵ��ʲ��ظ����㣻̫���ĵ���ֻ����ǰ10����ĸ	����ȷ	2 ms	244KB
2	��ȫ��ͬ	����ȷ	2 ms	256KB
3	��ȫ��ͬ	����ȷ	2 ms	152KB
4	���N��M����1���ļ�������ȫ�����ʣ���1�����ʳ����������ļ���	����ȷ	75 ms	2032KB*/
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
	for(int j=0; j<n; j++) {
		while(1) {
			char*temp=scan();
			if(temp) {
				if(temp[0]=='#') {
//					printf("+EOF+");
					break;
				}
				Insert(j+1,temp);
			}
		}
	}
	int m;
	scanf("%d",&m);
	while(m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)printf("100.0%%\n");//�������ϰ���ŷ�������ӡ����� 
		else
			printf("%.1f%%\n",Same[a][b]*100.0/(Sum[a]+Sum[b]-Same[a][b]));

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
//	printf("#");
	static char temp[11];
	static int Flag_br=0;
	int i=0;
	char c;
	while(1) {
		c=getchar();
		switch(c) {
			case '#' :
				if(Flag_br==1) {
					c=getchar();
					if(c=='\n') {
						temp[0]='#';
						temp[1]='\0';
						return temp;
					}
				}
			default:
				switch(c) {
					case 'a'...'z':
						if(i<10)
							temp[i++]=c;
						break;
					case 'A'...'Z':
						if(i<10)
							temp[i++]=c-'A'+'a';
						break;

					default:
						if(c=='\n')Flag_br=1;
						else Flag_br=0;

						temp[i]='\0';
						if(i>2) {
//							printf("{%s}",temp);
							return temp;
						} else {
//							printf("{}");
							return NULL;
						}
						break;
				}
				break;
		}
	}
}
