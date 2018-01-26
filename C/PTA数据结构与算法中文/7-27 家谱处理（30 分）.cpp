#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/* ������ ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-08-30 10:31 	ȫ����ȷ 	25 	5-27 	gcc 	1 	1 	569985011
���Ե��� ���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	18/18 	1 	1
���Ե�2 	����ȷ 	2/2 	1 	1
���Ե�3 	����ȷ 	5/5 	1 	1
���Ե�4 	����ȷ 	5/5 	1 	1
�鿴����*/
typedef struct node *Node;
struct node {
	char Name[11];
	int space;
	int  Parant;
};

Node Tree;
int n;

int Scan(char*);
int Trace(int);
int judgeParent(int,int);//����
int judgeSibling(int,int);//�ֵ�
int judgeAncestor(int,int);//����
void work();
int Index(char*);

int main() {
	int m;
	scanf("%d%d",&n,&m);
	Tree=(Node)malloc(sizeof(struct node)*n);
	getchar();//�������
	for(int i=0; i<n; i++) {
		Tree[i].space=Scan(Tree[i].Name);
		Tree[i].Parant=i;
	}
	Tree[0].Parant=-1;

	for(int i=0; i<m; i++) {
		work();
		getchar();
	}

	return 0;
}
int judgeParent(int x,int y) {
	if(Tree[x].Parant==x)Tree[x].Parant=Trace(x);
	return Tree[x].Parant==y;
}
int judgeSibling(int x,int y) {
	if(Tree[x].Parant==x)Tree[x].Parant=Trace(x);
	if(Tree[y].Parant==y)Tree[y].Parant=Trace(y);
	return Tree[x].Parant==Tree[y].Parant;
}
int judgeAncestor(int x,int y) {
	while(x!=-1) {
		if(judgeParent(x,y))return 1;
		else x=Tree[x].Parant;
	}
	return 0;
}

void work() {
	char StrX[11],StrY[11],relation[11];
	scanf("%s%*s%*s%s%*s%s",StrX,relation,StrY);
//	printf("%s - %s - %s\n",StrX,relation,StrY);

	int X=Index(StrX);
	int Y=Index(StrY);
//	printf("%d   -    %d",X,Y);
	int result;
	switch(relation[0]) {
		case 'c':
			result=judgeParent(X,Y);
			break;
		case 'p':
			result=judgeParent(Y,X);
			break;
		case 's':
			result=judgeSibling(X,Y);
			break;
		case 'd':
			result=judgeAncestor(X,Y);
			break;
		case 'a':
			result=judgeAncestor(Y,X);
			break;
		default:
			result=-1;
			break;
	}



	if(result==1)printf("True\n");
	else if(!result)printf("False\n");
//	else printf("ERROR:ϵͳ����ʶ����ָ����ϵ��\n");
}


int Index(char*a) {
	for(int i=0; i<n; i++) {
//		printf("*");
		if(strcmp(Tree[i].Name,a)==0)return i;
	}
// 	printf("ERROR:�������������ڣ�\n");
	return -1;
}

int Trace(int child) { //��ǰ������һ�����������ٵľ������ĸ���

	for(int i=child-1; i>=0; i--) {
		if(Tree[i].space<Tree[child].space) {
//		printf("%d's parent is %d'",child,i);
			return i;
		}
	}
	return -1;//���û�У���ô�������ǵ������ˡ�
}

int Scan(char*p) {
	char c;
	int space=0;

	while((c=getchar())==' ')space++;//��¼�ַ���ǰ��Ŀո�����

	do {
		*p++=c;
	} while((c=getchar())!='\n');
	*p='\0';

	return space;
}
