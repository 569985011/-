#include <stdio.h>
#include <stdlib.h>
/*
评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-06 18:06	答案正确	10	4-3	gcc	2	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	8/8			1		1
测试点2	答案正确	1/1			2		1
测试点3	答案正确	1/1			1		1
*/
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(){ /* 细节在此不表 */
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

/* 你的代码将被嵌在这里 */
int Length(List L){
	int n=0;
	while(L){
		L=L->Next;++n;
	}return n;
}
