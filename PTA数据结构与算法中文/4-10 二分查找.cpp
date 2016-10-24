#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-09 19:45	答案正确	20	4-10	gcc	34	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	10/10		2		1
测试点2	答案正确	2/2			14		1
测试点3	答案正确	1/1			1		1
测试点4	答案正确	1/1			1		1
测试点5	答案正确	2/2			11		1
测试点6	答案正确	2/2			34		1
测试点7	答案正确	2/2			16		1
*/
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput() /* 裁判实现，细节不表。元素从下标1开始存储 */
{int n;
scanf("%d",&n);
List Tbl=(List)malloc(sizeof(struct LNode));
//printf("%d\n",sizeof(LNode));//验证发现数组空间也是一并声明过了，不必另造 
for(int i=1;i<n+1;i++){
	scanf("%d",&Tbl->Data[i]);
}
Tbl->Last=n;
return Tbl;
}
Position BinarySearch( List Tbl, ElementType K );

int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List Tbl, ElementType K ){
	if(Tbl->Last>MAXSIZE)Tbl->Last=MAXSIZE-1;
	int left=1,right=Tbl->Last;//Last->实际地址 
	
	while(left<=right){//
		int mid=(left+right)/2;
		if(Tbl->Data[mid]==K)return mid;
		if(Tbl->Data[mid]>K)right=mid-1;
		else left=mid+1;
		
	}
	return NotFound;
}
