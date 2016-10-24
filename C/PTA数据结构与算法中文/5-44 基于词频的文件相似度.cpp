#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Big(a,n) ((a)>(b))?(a):(b)
/*ƽ̨��֧��ʹ��stricmp.*/
/* ������ ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-08-30 14:51 	������ȷ 	26 	5-44 	gcc 	2 	1 	569985011
���Ե��� ���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	18/18 	1 	1
���Ե�2 	����ȷ 	4/4 	2 	1
���Ե�3 	����ȷ 	2/2 	2 	1
���Ե�4 	����ȷ 	2/2 	1 	1
���Ե�5 	���г�ʱ 	0/4 	0 	0
�鿴����*/
typedef struct node *Node;
struct node {
	char*Words;
//	int Number;//������Ǵʻ� ���������ظ��Ĵʻ㲻��Ҫ����
	Node Next;
};

char*scan();
Node Insert(Node,char*);
void cmp(Node,Node);

int main() {
	int n;
	scanf("%d",&n);
	Node Head[101]= {0}; //��ʼ��Ϊ��

	for(int i=1; i<=n; i++) {
//		printf("\n--\n");
		int flag=1;
		while(flag) {
			char*temp=scan();
			int len=strlen(temp);
			if(len==1&&temp[0]=='#')flag=0;
			else if(len>=3) {
//				printf("{%s}",temp);
				Head[i]=Insert(Head[i],temp);
			}
		}
//		Node temp=Head[i];
//		while(temp) {
//			printf("[%s]",temp->Words);
//			temp=temp->Next;
//		}
	}

	int m;
	scanf("%d",&m);
	while(m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		cmp(Head[a],Head[b]);
	}

	return 0;
}

void cmp(Node a,Node b) {
	if(a&&b) {
		int Total=0;
		int Same=0;
		while(a&&b) {
			++Total;
//			printf("{%s-%s}",a->Words,b->Words);
			int flag=strcmp(a->Words,b->Words);
			if(!flag) {
				++Same;
				a=a->Next;
				b=b->Next;
			} else if(flag<0) {
				a=a->Next;
			} else {
				b=b->Next;
			}
		}
		while(a) {
			++Total;
			a=a->Next;
		}
		while(b) {
			++Total;
			b=b->Next;
		}
		printf("%.1f%%\n",Same*100.0/Total);
	} else printf("0.0%%\n");
}

char*scan() {
	static char temp[11];
	int i=0;
	char c;
	do {
		c=getchar();
		if(c>='A'&&c<='Z') {
			if(i<10)temp[i++]=c+'a'-'A';
		} else if(c>='a'&&c<='z') {
			if(i<10)temp[i++]=c;
		} else if(c=='#') {
			temp[i++]=c;
			break;
		} else break;
	} while(1);
	temp[i]='\0';
	return temp;
}

Node Insert(Node h,char*K) {
	if(!h||strcmp(h->Words,K)>0) {
		Node temp=(Node)malloc(sizeof(struct node));
		temp->Next=h;
//		temp->Number=1;
		temp->Words=(char*)malloc(sizeof(strlen(K))) ;
		strcpy(temp->Words,K);
		return temp;
	} else if(strcmp(h->Words,K)<0) h->Next=Insert(h->Next,K);
	return h;
}
