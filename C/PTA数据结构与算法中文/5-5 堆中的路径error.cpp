#include <stdlib.h>
#include <stdio.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-12 22:16	������ȷ	15	5-5	gcc	8	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	13/13		2		1
���Ե�2	�𰸴���	0/6			1		1
���Ե�3	����ȷ	2/2			8		1
���Ե�4	�𰸴���	0/4			2		1
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
MinHeap Create(int MaxSize);//����һ���յ�С���� 
Boolean IsFull(MinHeap H);//�ж϶�����
Boolean Insert(MinHeap H,ElementType X);//����
Boolean IsEmpty(MinHeap H);//�ж϶ѿշ�
ElementType DeleteMin(MinHeap H);//��ȡ���Ԫ�ز�ɾ�� 
Boolean PrintPath(MinHeap,ElementType);
int main(){
int n,m;int key;
 	scanf("%d",&n);
	 scanf("%d",&m); 
 
 	MinHeap H=Create(n);
 	
 	for(int i=0;i<n;i++){
	scanf("%d",&key);
	Insert(H,key);
//	if(Insert(H,key)==false)printf("����\n");
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
MinHeap Create(int MaxSize){//����һ���յ�С���� 
if(MaxSize<=0)return NULL;

MinHeap H=(MinHeap)malloc(sizeof(struct Heap));

H->heap=(ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));
H->MaxSize=0;
H->heap[0]=-19999;//ȷ����xiao�����ڱ�����
H->MinData=0;
 return H;
} 

Boolean IsFull(MinHeap H){//�ж϶�����
	if(!H)return true;//�������ɲ��� 
	if(H->MaxSize==sizeof(H->heap))return true;
	return false;
}

Boolean Insert(MinHeap H,ElementType X){//����
	if(!H||IsFull(H)){
//		printf("���������ɲ��롣\n");
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
Boolean IsEmpty(MinHeap H){//�ж϶ѿշ�
	if(!H)return true;//�նѲ�ִ��ɾ������ 
	if(H->MaxSize==0)return true;
	return false;
}
ElementType DeleteMin(MinHeap H){//��ȡ��СԪ�ز�ɾ�� 
	if(IsEmpty(H)){
		printf("�ѿգ����ɶ�ȡ\n");
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
