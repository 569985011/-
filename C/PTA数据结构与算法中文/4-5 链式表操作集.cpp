#include <stdio.h>
#include <stdlib.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-06 20:57	����ȷ	20	4-5	gcc	2	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12		2		1
���Ե�2	����ȷ	4/4			1		1
���Ե�3	����ȷ	4/4			1		1
*/
#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Position Find(List L,ElementType X){
	List F=L;
	while(F){
		if(F->Data==X)return F;
		F=F->Next;
	}
	return ERROR;
}
List Insert(List L,ElementType X,Position P){
	List head=L;
	if(L==P){head=(List)malloc(sizeof(struct LNode));
	head->Data=X;head->Next=P;return head;
	}
	while(L){
		if(L->Next==P)break;
		L=L->Next;
	}
	if(!L){printf("Wrong Position for Insertion\n");
	return ERROR;
	}

	L->Next=(List)malloc(sizeof(struct LNode));
	L->Next->Data=X;
	L->Next->Next=P;
	
return head;	
}
List Delete(List L,Position P){
if(L==P){L=L->Next;
	return L;
}
	List head=L;
while(L){
	if(L->Next==P)break;
	L=L->Next;
}
if(!L){printf("Wrong Position for Deletion\n");
	return ERROR;
}
L->Next=P->Next;free(P);

	return head;
}
