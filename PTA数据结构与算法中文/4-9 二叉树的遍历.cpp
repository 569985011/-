#include <stdio.h>
#include <stdlib.h>
/*
������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-09 19:01	����ȷ	25	4-9	gcc	1	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	13/13		1		1
���Ե�2	����ȷ	4/4			1		1
���Ե�3	����ȷ	4/4			1		1
���Ե�4	����ȷ	2/2			1		1
���Ե�5	����ȷ	2/2			1		1
*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree() { /* ʵ��ϸ�ں��� */
	BinTree a=(BinTree)malloc(sizeof(struct TNode));
	a->Left=(BinTree)malloc(sizeof(struct TNode));
	a->Right=(BinTree)malloc(sizeof(struct TNode));
	BinTree l,r;
	a->Data='a';
	l=a->Left;
	r=a->Right;
	l->Data='b';
	r->Data='c';
	l->Left=(BinTree)malloc(sizeof(struct TNode));
	l->Left->Data='d';
	l->Right=(BinTree)malloc(sizeof(struct TNode));
	l->Right->Data='f';
	l->Left->Left=NULL;
	l->Left->Right=NULL;
	l->Right->Left=(BinTree)malloc(sizeof(struct TNode));
	l->Right->Left->Data='e';
	l->Right->Right=NULL;
	l->Right->Left->Left=NULL;
	l->Right->Left->Right=NULL;
	r->Left=(BinTree)malloc(sizeof(struct TNode));
	r->Left->Data='g';
	r->Left->Left=NULL;
	r->Left->Right=(BinTree)malloc(sizeof(struct TNode));
	r->Left->Right->Data='h';
	r->Left->Right->Left=NULL;
	r->Left->Right->Right=NULL;
	r->Right=(BinTree)malloc(sizeof(struct TNode));
	r->Right->Data='i';
	r->Right->Left=NULL;
	r->Right->Right=NULL;
	return a;
}
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main() {
	BinTree BT = CreatBinTree();
	printf("Inorder:");
	InorderTraversal(BT);
	printf("\n");
	printf("Preorder:");
	PreorderTraversal(BT);
	printf("\n");
	printf("Postorder:");
	PostorderTraversal(BT);
	printf("\n");
	printf("Levelorder:");
	LevelorderTraversal(BT);
	printf("\n");
	
	return 0;
}
/* ��Ĵ��뽫��Ƕ������ */

void InorderTraversal( BinTree BT ) {
	if(BT) {
		InorderTraversal(BT->Left);
		printf(" %c",BT->Data);
		InorderTraversal(BT->Right);
	}

}
void PreorderTraversal( BinTree BT ) {

	if(BT) {
		printf(" %c",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
void PostorderTraversal( BinTree BT ) {
	if(BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c",BT->Data);
	}
}


void LevelorderTraversal( BinTree BT ) {
	if(!BT)return ;
	int Maxsize=100;//ͬһʱ������������� 
	BinTree* a=(BinTree*)malloc(sizeof(BinTree)*Maxsize);
	a[0]=BT; 
	int left=-1,right=0;
	while(left!=right) {
		BinTree t=a[++left%Maxsize];
			printf(" %c",t->Data);
		if(t->Left){a[++right%Maxsize]=t->Left;}
		if(t->Right){a[++right%Maxsize]=t->Right;}
	}

}
