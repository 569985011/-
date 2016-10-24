#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-10 00:07	答案正确	30	4-12	gcc	1	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	18/18 		1		1
测试点2	答案正确	4/4   		1		1
测试点3	答案正确	4/4 		1		1
测试点4	答案正确	2/2 		1		1
测试点5	答案正确	2/2 		1		1
*/
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void InorderTraversal( BinTree BT ) {/* 中序遍历，由裁判实现，细节不表 */
	if(BT) {
		InorderTraversal(BT->Left);
		printf(" %d",BT->Data);
		InorderTraversal(BT->Right);
	}

}
void PreorderTraversal( BinTree BT ) {/* 先序遍历，由裁判实现，细节不表 */

	if(BT) {
		printf(" %d",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main() {
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for ( i=0; i<N; i++ ) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:");
	PreorderTraversal(BST);
	printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for( i=0; i<N; i++ ) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for( i=0; i<N; i++ ) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:");
	InorderTraversal(BST);
	printf("\n");

	return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ) { //二分生长树

	BinTree NewT=(BinTree)malloc(sizeof(struct TNode));
	NewT->Data=X;
	NewT->Left=NULL;
	NewT->Right=NULL;

	BinTree head=BST;
	while(BST) {
		if(BST->Data>=X) {
			if(BST->Left)BST=BST->Left;
			else {//对于相同的数将其插入左子树，为左子树的最右结点 
				BST->Left=NewT;
				return head;
			}
		} else {
			if(BST->Right)BST=BST->Right;
			else {
				BST->Right=NewT;
				return head;
			}
		}
	}
	return NewT;//若为空树 则新建
}
BinTree Delete( BinTree BST, ElementType X ) {
	BinTree head=BST;
	BinTree t=Find(BST,X);
	if(!t) {
		printf("Not Found\n");
		return BST;
	}
	BinTree m=FindMax(t->Left);	
	if(m) {//左子树处理 
		t->Data=m->Data;
		if(t->Left==m)t->Left=m->Left;
		else {
			t=t->Left;
			while(t->Right!=m)t=t->Right;
			t->Right=m->Left;
		}
	} else { 
		m=FindMin(t->Right);
		if(m) {//左子树为空时 
			t->Data=m->Data;
			if(t->Right==m)t->Right=m->Right;
			else {
				t=t->Right;
				while(t->Left!=m)t=t->Left;
				t->Left=m->Right;
			}
		} else { //当其为叶节点时
			if(BST==t)return NULL;	
			while(BST) {
				if(BST->Data>=t->Data) {
					if(BST->Left==t)BST->Left=NULL;
					BST=BST->Left;
				} else {
					if(BST->Right==t)BST->Right=NULL;
					BST=BST->Right;
				}
			}
		}

	}
	return head;
}
Position Find( BinTree BST, ElementType X ) {
	BinTree h=BST;
	while(h) {
		if(h->Data==X)break;
		else if(h->Data<X)h=h->Right;
		else h=h->Left;
	}

	return h;
}
Position FindMin( BinTree BST ) {
	BinTree h=BST;
	if(!h)while(h->Left)h=h->Left;
	return h;
}
Position FindMax( BinTree BST ) {
	if(!BST)return NULL;
	BinTree h=BST;
	while(h->Right)h=h->Right;
	return h;
}
