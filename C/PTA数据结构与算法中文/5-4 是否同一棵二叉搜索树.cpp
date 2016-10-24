#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-11 17:06	����ȷ	25	5-4	gcc	17	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12		2		1
���Ե�2	����ȷ	8/8			2		1
���Ե�3	����ȷ	3/3			1		1
���Ե�4	����ȷ	2/2			17		1

*/

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
BinTree Insert(BinTree BST,ElementType X);
int Compare(BinTree,BinTree);
int Read(){
	int num,times=0;
	scanf("%d",&num);
	if(num)scanf("%d",&times);
	BinTree TempTree=NULL;
	int key;
	for(int i=0;i<num;i++){
		scanf("%d",&key);
		TempTree=Insert(TempTree,key);
	}

	for(int j=0;j<times;j++){
		BinTree CaseTree=NULL;	
		for(int i=0;i<num;i++){
			scanf("%d",&key);
		CaseTree=Insert(CaseTree,key);	
		}
		if(key=Compare(TempTree,CaseTree))printf("No\n");else printf("Yes\n");
		free(CaseTree);
	}
	return num;
}
int main(){
int k;
while(k=Read()); 


return 0;
}
int Compare(BinTree TempT,BinTree CaseT){
	 int flag=0;
	if(TempT&&!flag){if(!CaseT)return 1;
		if(TempT->Data!=CaseT->Data)return 1;
		if(Compare(TempT->Left,CaseT->Left))return 1;
		if(Compare(TempT->Right,CaseT->Right))return 1;
	}else if(CaseT)return 1;

	return flag;
}

BinTree Insert( BinTree BST, ElementType X ) { //����������

	BinTree NewT=(BinTree)malloc(sizeof(struct TNode));
	NewT->Data=X;
	NewT->Left=NULL;
	NewT->Right=NULL;

	BinTree head=BST;
	while(BST) {
		if(BST->Data>=X) {
			if(BST->Left)BST=BST->Left;
			else {
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

