#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-07 14:58	答案错误	0	4-7	gcc	无	无	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	多种错误	0/10	0	0
测试点2	多种错误	0/4	0	0
测试点3	多种错误	0/4	0	0
测试点4	多种错误	0/2	0	0
我也是没脾气了，，基本都是报超时///错哪了？ 
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

/* 你的代码将被嵌在这里 */
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
