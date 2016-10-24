#include <stdio.h>
#include <stdlib.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-09 19:49	����ȷ	15	4-11	gcc	17	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	9/9			1		1
���Ե�2	����ȷ	2/2			1		1
���Ե�3	����ȷ	2/2			17		1
���Ե�4	����ȷ	2/2			8		1
*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
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
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void PreorderPrintLeaves(BinTree BT){
	if(BT){
		if(!BT->Left&&!BT->Right)printf(" %c",BT->Data);
		 PreorderPrintLeaves(BT->Left);
		 PreorderPrintLeaves(BT->Right);
	}
} 
