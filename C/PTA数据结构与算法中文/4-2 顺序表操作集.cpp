#include <stdio.h>
#include <stdlib.h>
/*
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-06 18:03	答案正确	20	4-2	gcc	1	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	12/12		1		1
测试点2	答案正确	4/4			1		1
测试点3	答案正确	4/4			1		1
*/
#define MAXSIZE 5
#define ERROR -1
//typedef enum BOOL{false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
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

/* 你的代码将被嵌在这里 */
