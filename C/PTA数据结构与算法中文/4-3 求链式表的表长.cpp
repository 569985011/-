#include <stdio.h>
#include <stdlib.h>
/*
������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-06 18:06	����ȷ	10	4-3	gcc	2	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	8/8			1		1
���Ե�2	����ȷ	1/1			2		1
���Ե�3	����ȷ	1/1			1		1
*/
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(){ /* ϸ���ڴ˲��� */
	int n;List a=(List)malloc(sizeof(struct LNode));
	List head=a;
	while(1){
	scanf("%d",&n);if(n==-1)break;
		a->Next=(List)malloc(sizeof(struct LNode));
		a=a->Next;a->Data=n;

	}a->Next=NULL;
	return head->Next;
}

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int Length(List L){
	int n=0;
	while(L){
		L=L->Next;++n;
	}return n;
}
