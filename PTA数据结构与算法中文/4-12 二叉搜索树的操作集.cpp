#include <stdio.h>
#include <stdlib.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-10 00:07	����ȷ	30	4-12	gcc	1	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	18/18 		1		1
���Ե�2	����ȷ	4/4   		1		1
���Ե�3	����ȷ	4/4 		1		1
���Ե�4	����ȷ	2/2 		1		1
���Ե�5	����ȷ	2/2 		1		1
*/
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void InorderTraversal( BinTree BT ) {/* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
	if(BT) {
		InorderTraversal(BT->Left);
		printf(" %d",BT->Data);
		InorderTraversal(BT->Right);
	}

}
void PreorderTraversal( BinTree BT ) {/* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

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
/* ��Ĵ��뽫��Ƕ������ */
BinTree Insert( BinTree BST, ElementType X ) { //����������

	BinTree NewT=(BinTree)malloc(sizeof(struct TNode));
	NewT->Data=X;
	NewT->Left=NULL;
	NewT->Right=NULL;

	BinTree head=BST;
	while(BST) {
		if(BST->Data>=X) {
			if(BST->Left)BST=BST->Left;
			else {//������ͬ�������������������Ϊ�����������ҽ�� 
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
	return NewT;//��Ϊ���� ���½�
}
BinTree Delete( BinTree BST, ElementType X ) {
	BinTree head=BST;
	BinTree t=Find(BST,X);
	if(!t) {
		printf("Not Found\n");
		return BST;
	}
	BinTree m=FindMax(t->Left);	
	if(m) {//���������� 
		t->Data=m->Data;
		if(t->Left==m)t->Left=m->Left;
		else {
			t=t->Left;
			while(t->Right!=m)t=t->Right;
			t->Right=m->Left;
		}
	} else { 
		m=FindMin(t->Right);
		if(m) {//������Ϊ��ʱ 
			t->Data=m->Data;
			if(t->Right==m)t->Right=m->Right;
			else {
				t=t->Right;
				while(t->Left!=m)t=t->Left;
				t->Left=m->Right;
			}
		} else { //����ΪҶ�ڵ�ʱ
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
