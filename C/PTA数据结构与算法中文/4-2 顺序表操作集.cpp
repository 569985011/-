#include <stdio.h>
#include <stdlib.h>
/*
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-06 18:03	����ȷ	20	4-2	gcc	1	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12		1		1
���Ե�2	����ȷ	4/4			1		1
���Ե�3	����ȷ	4/4			1		1
*/
#define MAXSIZE 5
#define ERROR -1
//typedef enum BOOL{false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty(){
List a=(List)malloc(sizeof(struct LNode));
a->Last=0;
return a;
} 
Position Find( List L, ElementType X ){
	if(!L)return ERROR;
	for(int i=0;i<L->Last;i++){
		if(L->Data[i]==X)return i;
	}
	return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
	if(!L)return false;
	if(L->Last==MAXSIZE){
		printf("FULL");return false;
	}	if(P<0||P>L->Last){
		printf("ILLEGAL POSITION");return false;
	}

	for(int i=L->Last;i>P;i--){
		L->Data[i]=L->Data[i-1];
	}L->Data[P]=X;
	++L->Last;
	return true;
	
}

bool Delete( List L, Position P ){
	if(!L)return false;
	if(P>=L->Last||P<0){
		printf("POSITION %d EMPTY",P);return false;
	}
	--L->Last;
	for(int i=P;i<L->Last;i++){
		L->Data[i]=L->Data[i+1];
	}
	return true;
}

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
