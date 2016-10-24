#include <stdio.h>
#include <stdlib.h>
/*
������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-06 21:28	����ȷ	20	4-6	gcc	22	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12		1		1
���Ե�2	����ȷ	4/4			22		1
���Ե�3	����ȷ	4/4			1		1
*/
#define ERROR NULL
//typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
List MakeEmpty()//������������һ���յ����Ա�
{List a=(List)malloc(sizeof(struct LNode));
a->Data=0;a->Next=NULL;
return a;
}
Position Find( List L, ElementType X )//���������Ա���X��λ�á����Ҳ����򷵻�ERROR��
{List F=L;
while(F){
	if(F->Data==X)break;
	F=F->Next;
}
return F;

}
bool Insert( List L, ElementType X, Position P )//����X������λ��Pָ��Ľ��֮ǰ������true���������Pָ��Ƿ�λ�ã����ӡ��Wrong Position for Insertion��������false��
{	List F=L;
while(F->Next){
	if(F->Next==P)break;
	F=F->Next;
}if(F->Next!=P){printf("Wrong Position for Insertion\n");
return false;
}F->Next=(List)malloc(sizeof(struct LNode));
F->Next->Data=X;
F->Next->Next=P;
return true;
}
bool Delete( List L, Position P )//����λ��P��Ԫ��ɾ��������true��������Pָ��Ƿ�λ�ã����ӡ��Wrong Position for Deletion��������false��
{List F=L;
if(!P){
	printf("Wrong Position for Deletion\n");
return false;
}

while(F->Next){
	if(F->Next==P)break;
	F=F->Next;
}if(F->Next!=P){
	printf("Wrong Position for Deletion\n");
return false;
}F->Next=P->Next;
return true;
}
