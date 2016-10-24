#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-06 18:26	答案正确	10	4-4	gcc	1	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	8/8			1		1
测试点2	答案正确	1/1			1		1
测试点3	答案正确	1/1			1		1
*/
#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */
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
ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType FindKth(List L,int K){

	while(--K){
			if(!L)return ERROR;
		L=L->Next;
	
	}
	if(!L)return ERROR;
	return L->Data;
	
}
