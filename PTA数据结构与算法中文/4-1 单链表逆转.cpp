#include <stdio.h>
#include <stdlib.h>
/*
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-06 16:55	答案正确	20	4-1	gcc	2	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	11/11		2		1
测试点2	答案正确	3/3			1		1
测试点3	答案正确	3/3			1		1
测试点4	答案正确	3/3			1		1

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

/* 你的代码将被嵌在这里 */
