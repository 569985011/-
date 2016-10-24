#include<stdlib.h>
#include<stdio.h>
#define ERROR 999999
/* 评测结果 时间 	结果 	得分 	题目 	编译器 	用时（ms） 	内存（MB） 	用户
2016-09-03 23:44 	答案正确 	25 	5-22 	gcc 	2 	1 	569985011
测试点结果 测试点 	结果 	得分/满分 	用时（ms） 	内存（MB）
测试点1 	答案正确 	15/15 	2 	1
测试点2 	答案正确 	4/4 	1 	1
测试点3 	答案正确 	6/6 	2 	1
查看代码*/
typedef int ElementType;

typedef struct stack {
	ElementType*S;
	int Left;
	int Right;
	int MaxSize;
}*Stack ;


Stack Creat(int);
int IsFull(Stack S);//：判断堆栈S是否已满，返回1或0；
int IsEmpty (Stack S );//：判断堆栈S是否为空，返回1或0；
void Push(Stack S, ElementType item );//：将元素item压入堆栈S；
ElementType Pop(Stack S );//：删除并返回S的栈顶元素。
void AddQ(ElementType item);//入队
ElementType DeleteQ();//出队

Stack M,N;

int main() {

	int m1,m2;
	scanf("%d%d",&m1,&m2);
	M=Creat(m1>m2?m1:m2);//入列栈
	N=Creat(m1>m2?m2:m1);//出队栈
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

int IsFull(Stack S) { //：判断堆栈S是否已满，返回1或0；
	if((S->Right+1)%S->MaxSize ==S->Left%S->MaxSize)return 1;
	return 0;
}
int IsEmpty (Stack S ) { //：判断堆栈S是否为空，返回1或0；
	if(S->Right%S->MaxSize==S->Left%S->MaxSize)return 1;
	return 0;
}
void Push(Stack S, ElementType item ) { //：将元素item压入堆栈S；
	S->S[(++S->Right)%S->MaxSize]=item;
}
ElementType Pop(Stack S ) { //：删除并返回S的栈顶元素。
	ElementType temp=S->S[++S->Left%S->MaxSize];
	return temp;
}
void AddQ(ElementType item) { //入队
	if(M->Right-M->Left<N->MaxSize-1) {
		Push(M,item);
		return;
	} else if(IsEmpty(N)) {
		while(!IsEmpty(M))Push(N,Pop(M));
		Push(M,item);
	} else printf("ERROR:Full\n");
}


ElementType DeleteQ() { //出队
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
