#include <stdio.h>
#include <stdlib.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-07 14:58	�𰸴���	0	4-7	gcc	��	��	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	���ִ���	0/10	0	0
���Ե�2	���ִ���	0/4	0	0
���Ե�3	���ִ���	0/4	0	0
���Ե�4	���ִ���	0/2	0	0
��Ҳ��ûƢ���ˣ����������Ǳ���ʱ///�����ˣ� 
*/
#define ERROR 1e8
typedef int ElementType;
//typedef enum { push, pop, end } Operation;
//typedef enum { false, true } bool;
typedef int Position;
struct SNode {
	ElementType *Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

/*Operation*/int GetOp()  /* details omitted */
{	int d;
	scanf("%d",&d);
	return d;
}
void PrintStack( Stack S, int Tag ) { /* details omitted */
	printf("Pop from Stack %d :",Tag);
	switch(Tag) {
		case 1:
			for(int i=0; i<S->Top1; i++) {
				if(i)printf(" ");
				printf("%d",S->Data[i]);
			}
			break;
		case 2:
			for(int i=S->Top2+1; i<S->MaxSize; i++) {
				if(i)printf(" ");
				printf("%d",S->Data[i]);
			}
			break;
		default:
			break;
	}
	printf("\n");
}
int main() {

	int N, Tag, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while ( !done ) {
		switch( GetOp() ) {
			case 0://push:
				scanf("%d %d", &Tag, &X);
				if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
				break;
			case 1://pop:
				scanf("%d", &Tag);
				X = Pop(S, Tag);
				if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
				break;
			case 2://end:
				PrintStack(S, 1);
				PrintStack(S, 2);
				done = 1;
				break;
		}
	}
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Stack CreateStack( int MaxSize ) {
	Stack a=(Stack)malloc(sizeof(struct SNode));

	a->Data=(ElementType*)malloc(sizeof(ElementType)*MaxSize);
	a->MaxSize=MaxSize-1;
	a->Top1=0;
	a->Top2=MaxSize-1;
	return a;
}
bool Push( Stack S, ElementType X, int Tag ) {
	if(!S)return false;
	if(S->Top1>S->Top2) {
		printf("Stack Full\n");
		return false;
	}
	switch(Tag) {
		case 1:
			S->Data[S->Top1]=X;S->Top1++;
			break;
		case 2:
			S->Data[S->Top2]=X;S->Top2--; 
			break;
		default:
			return false;
	}
	return true;
}
ElementType Pop( Stack S, int Tag ) {
	if(!S)return ERROR;
	ElementType X;
	switch(Tag) {
		case 1:
			if(0==S->Top1) {
				printf("Stack 1 Empty\n");
				return ERROR;
			}X=S->Data[S->Top1--];
			break;
		case 2:
			if(S->Top2==S->MaxSize) {
				printf("Stack 2 Empty\n");
				return ERROR;
			}X=S->Data[S->Top2++];
			break;
		default:return ERROR;break;
	}
	return X;
}
