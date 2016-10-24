#include <stdio.h>
#include <stdlib.h>
/*ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-09 16:59	����ȷ	20	4-8	gcc	2	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12	2			1
���Ե�2	����ȷ	3/3		1			1
���Ե�3	����ȷ	3/3		1			1
���Ե�4	����ȷ	1/1		1			1
���Ե�5	����ȷ	1/1		1			1
*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree() /* ʵ��ϸ�ں��� */
{	BinTree a=(BinTree)malloc(sizeof(struct TNode));
a->Left=(BinTree)malloc(sizeof(struct TNode));
a->Right=(BinTree)malloc(sizeof(struct TNode));
BinTree l,r;
l=a->Left;r=a->Right;
l->Left=(BinTree)malloc(sizeof(struct TNode));
l->Right=(BinTree)malloc(sizeof(struct TNode));
l->Left->Left=NULL;
l->Left->Right=NULL;
l->Right->Left=(BinTree)malloc(sizeof(struct TNode));
l->Right->Right=NULL;
l->Right->Left->Left=NULL;
l->Right->Left->Right=NULL;
r->Left=(BinTree)malloc(sizeof(struct TNode));
r->Left->Left=NULL;
r->Left->Right=(BinTree)malloc(sizeof(struct TNode));
r->Left->Right->Left=NULL;
r->Left->Right->Right=NULL;
r->Right=(BinTree)malloc(sizeof(struct TNode));
r->Right->Left=NULL;
r->Right->Right=NULL;
return a;
}
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */

int GetHeight(BinTree BT){
	int cnt =0; 
	if(BT){
		int l,r;
		l=GetHeight(BT->Left);
		r=GetHeight(BT->Right);
		if(l>r)cnt=l+1;else cnt=r+1;
	}
	return cnt;
}
