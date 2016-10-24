#include <stdio.h>
#include <stdlib.h>
/*时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-09 16:59	答案正确	20	4-8	gcc	2	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	12/12	2			1
测试点2	答案正确	3/3		1			1
测试点3	答案正确	3/3		1			1
测试点4	答案正确	1/1		1			1
测试点5	答案正确	1/1		1			1
*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree() /* 实现细节忽略 */
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
/* 你的代码将被嵌在这里 */

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
