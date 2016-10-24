#include <stdlib.h>
#include <stdio.h>
/*
*/
typedef struct node *Queue;
typedef int ElementType; 
struct node{
	ElementType *a;
	int front;
	int rear;
	int MaxSize;
};
Queue CreatQueue(int MaxSize);
int IsFullQ(Queue Q,int MaxSize) ;
void AddQ(Queue Q,ElementType item);
int IsEmptyQ(Queue Q);
ElementType DeleteQ(Queue Q);

int main(){

Queue Q=CreatQueue(10);
for(int i=0;i<99;i++){
	IsFullQ(Q,10);
	AddQ(Q,i);

}
printf("\n----\n");
for(int i=0;i<10;i++){
	printf("%d ",Q->a[i]);
}


return 0;
}

Queue CreatQueue(int MaxSize){
	Queue Q=(Queue)malloc(sizeof(struct node));
	Q->a=(ElementType*)malloc(sizeof(ElementType)*MaxSize);
	Q->front=0;
	Q->rear =-1;
	return Q;  
}
int IsFullQ(Queue Q,int MaxSize){
	return (Q->front+MaxSize==Q->rear);
}
void AddQ(Queue Q,ElementType item){
if(Q->front+Q->MaxSize<=Q->rear){
	printf("空间已满，插入失败");
	return; 
}Q->a[++Q->rear%Q->MaxSize]=item;
}
int IsEmptyQ(Queue Q){
	return (Q->front ==Q->rear);
}
ElementType DeleteQ(Queue Q){
	if(IsEmptyQ(Q)){
		printf("队列已空，读取失败");
		return -1;
	}
	return Q->a[++Q->front%Q->MaxSize];
}
