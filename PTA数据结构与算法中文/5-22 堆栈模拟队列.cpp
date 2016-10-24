#include<stdlib.h>
#include<stdio.h>
#define ERROR 999999
/* ������ ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-09-03 23:44 	����ȷ 	25 	5-22 	gcc 	2 	1 	569985011
���Ե��� ���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	15/15 	2 	1
���Ե�2 	����ȷ 	4/4 	1 	1
���Ե�3 	����ȷ 	6/6 	2 	1
�鿴����*/
typedef int ElementType;

typedef struct stack {
	ElementType*S;
	int Left;
	int Right;
	int MaxSize;
}*Stack ;


Stack Creat(int);
int IsFull(Stack S);//���ж϶�ջS�Ƿ�����������1��0��
int IsEmpty (Stack S );//���ж϶�ջS�Ƿ�Ϊ�գ�����1��0��
void Push(Stack S, ElementType item );//����Ԫ��itemѹ���ջS��
ElementType Pop(Stack S );//��ɾ��������S��ջ��Ԫ�ء�
void AddQ(ElementType item);//���
ElementType DeleteQ();//����

Stack M,N;

int main() {

	int m1,m2;
	scanf("%d%d",&m1,&m2);
	M=Creat(m1>m2?m1:m2);//����ջ
	N=Creat(m1>m2?m2:m1);//����ջ
	int flag=1;
	while(flag) {
		getchar();
		char C;
		scanf("%c",&C);
		ElementType item,temp;
//		printf("{[%c]",C);
		switch(C) {
			case 'A':
				scanf("%d",&item);
				AddQ(item);
				break;
			case 'D':
				temp=DeleteQ();
				if(temp!=ERROR) {
					printf("%d\n",temp);
				} else printf("ERROR:Empty\n");
				break;
			case 'T':
				flag=0;
				break;
		}
//		printf("}");
	}
	return 0;
}

int IsFull(Stack S) { //���ж϶�ջS�Ƿ�����������1��0��
	if((S->Right+1)%S->MaxSize ==S->Left%S->MaxSize)return 1;
	return 0;
}
int IsEmpty (Stack S ) { //���ж϶�ջS�Ƿ�Ϊ�գ�����1��0��
	if(S->Right%S->MaxSize==S->Left%S->MaxSize)return 1;
	return 0;
}
void Push(Stack S, ElementType item ) { //����Ԫ��itemѹ���ջS��
	S->S[(++S->Right)%S->MaxSize]=item;
}
ElementType Pop(Stack S ) { //��ɾ��������S��ջ��Ԫ�ء�
	ElementType temp=S->S[++S->Left%S->MaxSize];
	return temp;
}
void AddQ(ElementType item) { //���
	if(M->Right-M->Left<N->MaxSize-1) {
		Push(M,item);
		return;
	} else if(IsEmpty(N)) {
		while(!IsEmpty(M))Push(N,Pop(M));
		Push(M,item);
	} else printf("ERROR:Full\n");
}


ElementType DeleteQ() { //����
	ElementType temp;
	if(IsEmpty(N))while(!IsEmpty(M))Push(N,Pop(M));
	if(IsEmpty(N))return ERROR;
	else {
		temp=Pop(N);
		if(IsEmpty(M))while(!IsEmpty(N))Push(M,Pop(N));
	}
	return temp;
}
Stack Creat(int m) {
	Stack S=(Stack)malloc(sizeof(struct stack));
	S->S=(ElementType*)malloc(sizeof(ElementType)*(m+1));
	S->Left=-1;
	S->Right =-1;
	S->MaxSize =m+1;
	return S;
}
