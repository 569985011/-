#include <stdio.h>
#include <stdlib.h>
/*
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-06 16:55	����ȷ	20	4-1	gcc	2	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	11/11		2		1
���Ե�2	����ȷ	3/3			1		1
���Ե�3	����ȷ	3/3			1		1
���Ե�4	����ȷ	3/3			1		1

*/
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(){
int n;
scanf("%d",&n);List a=(List)malloc(sizeof(struct Node));
List head=a;
while(n--){
	scanf("%d",&a->Data);
	if(n){a->Next=(List)malloc(sizeof(struct Node));
	a=a->Next;
	}
}a->Next=NULL;
return head;
} 
void Print( List L ){
	while(L){
		printf("%d ",L->Data);
		L=L->Next;
	}
	printf("\n");
}

List Reverse( List L ){

	List b=NULL;
	List head=L;
	List a=L;
	if(!L)return L;
	while(L->Next){
	 a=L->Next;
	 L->Next=b;
	 b=L;L=a;
	}
	a->Next=b;
	L=head;
	return a;
}

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
