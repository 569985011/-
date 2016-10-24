#include <stdlib.h>
#include <stdio.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-12 22:16	部分正确	15	5-5	gcc	8	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	13/13		2		1
测试点2	答案错误	0/6			1		1
测试点3	答案正确	2/2			8		1
测试点4	答案错误	0/4			2		1
*/
#define true 1;
#define false 0;
#define Boolean int
//typedef bool Boolean;
typedef int ElementType;
typedef struct Heap{
ElementType *heap;
int MaxSize;
ElementType MinData;
}*MinHeap;

MinHeap ReadData(void);
MinHeap Create(int MaxSize);//创建一个空的小顶堆 
Boolean IsFull(MinHeap H);//判断堆满否
Boolean Insert(MinHeap H,ElementType X);//插入
Boolean IsEmpty(MinHeap H);//判断堆空否
ElementType DeleteMin(MinHeap H);//读取最大元素并删除 
Boolean PrintPath(MinHeap,ElementType);
int main(){
int n,m;int key;
 	scanf("%d",&n);
	 scanf("%d",&m); 
 
 	MinHeap H=Create(n);
 	
 	for(int i=0;i<n;i++){
	scanf("%d",&key);
	Insert(H,key);
//	if(Insert(H,key)==false)printf("出错\n");
	 }
	 
	 while(m--){
	 	scanf("%d",&key);
	 	PrintPath(H,key);
	 	if(m)printf("\n");
	 }
return 0;
}

MinHeap ReadData(void){
    
	 return NULL;
}
Boolean PrintPath(MinHeap H,ElementType X){//
if(X<1)return false;
while(X>H->MaxSize)X/=2;
			for(int j=X;j>=1;j/=2){
				if(j!=X)printf(" ");
				printf("%d",H->heap[j]);
			}
			return true;
			

	
}
MinHeap Create(int MaxSize){//创建一个空的小顶堆 
if(MaxSize<=0)return NULL;

MinHeap H=(MinHeap)malloc(sizeof(struct Heap));

H->heap=(ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));
H->MaxSize=0;
H->heap[0]=-19999;//确保够xiao以起到哨兵作用
H->MinData=0;
 return H;
} 

Boolean IsFull(MinHeap H){//判断堆满否
	if(!H)return true;//堆满不可插入 
	if(H->MaxSize==sizeof(H->heap))return true;
	return false;
}

Boolean Insert(MinHeap H,ElementType X){//插入
	if(!H||IsFull(H)){
//		printf("堆满，不可插入。\n");
		return false; 
	}

	int parent;
	for(parent=++H->MaxSize;H->heap[parent/2]>X;parent/=2 ){
		H->heap[parent]=H->heap[parent/2];
	}
	H->heap[parent]=X;
	return true; 
}
/*
Boolean IsEmpty(MinHeap H){//判断堆空否
	if(!H)return true;//空堆不执行删除操作 
	if(H->MaxSize==0)return true;
	return false;
}
ElementType DeleteMin(MinHeap H){//读取最小元素并删除 
	if(IsEmpty(H)){
		printf("堆空，不可读取\n");
		return false;
	}
	ElementType temp=H->heap[1];
	int child;
	for(child=1;child*2<=H->MaxSize;child*=2){
		child*=2;
		if(child!=H->MaxSize&&H->heap[child+1]<H->heap[child])
			child++;
		H->heap[child/2]=H->heap[child];	
	} 
	H->heap[child]=H->heap[H->MaxSize--];
	return temp;
}*/
