#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-09 19:49	答案正确	15	4-11	gcc	17	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	9/9			1		1
测试点2	答案正确	2/2			1		1
测试点3	答案正确	2/2			17		1
测试点4	答案正确	2/2			8		1
*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree() { /* 实现细节忽略 */
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
/* 你的代码将被嵌在这里 */
void PreorderPrintLeaves(BinTree BT){
	if(BT){
		if(!BT->Left&&!BT->Right)printf(" %c",BT->Data);
		 PreorderPrintLeaves(BT->Left);
		 PreorderPrintLeaves(BT->Right);
	}
} 
