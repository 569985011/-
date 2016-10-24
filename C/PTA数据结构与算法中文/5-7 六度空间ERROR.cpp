#include <stdio.h>
#include <stdlib.h>
/*
������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-15 09:54	������ȷ	27	5-7	gcc	14	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	18/18		1		1
���Ե�2	����ȷ	3/3			1		1
���Ե�3	����ȷ	3/3			1		1
���Ե�4	����ȷ	3/3			11		1
���Ե�5	�ڴ泬��	0/3			0		0

*/
typedef struct LNode *Vertex;
struct LNode {
	int Data;
	Vertex Next;
};
Vertex CreatV(int);
void Print(Vertex num,int n);
Vertex InsertV(Vertex,int);
Vertex EndofV(Vertex);
Vertex DFS(Vertex,int,int,int,Vertex);//�����������
Vertex BFS(Vertex,int);

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	int from,to;
	int* IsVisit=(int*)calloc(N+1,sizeof(int)); 
	Vertex V=CreatV(N+1);
	for(int i=0; i<M; i++) {
		scanf("%d%d",&from,&to);
		InsertV(&V[to],from);
		InsertV(&V[from],to);
	}

	for(int i=1; i<N+1; i++) {
		printf("%d: ",i);
//		Vertex num=DFS(V,N,i,6,NULL);//�������
		Vertex num=BFS(V,i);
		Print(num,N); 
		while(num){Vertex temp=num;
		num=num->Next;free(temp);
		}
	}
}
void Print(Vertex num,int n) {
	int cnt=0;
	if(!num) {
		printf("0.00%\n");
		return;
	}
//	printf("{");
	for(; num; num=num->Next) {
		++cnt;
//		printf("%d ",num->Data);
	}
//	printf(" }\n");

	printf("%.2f%%\n",cnt*100.0/n);
}
Vertex BFS(Vertex V,int X) {
	Vertex num=InsertV(NULL,X);int cen=6;
	Vertex temp=num,start,pause=num,end;
	while(temp){
		start=temp;
		Vertex friends=&V[temp->Data];
		while(friends){num=InsertV(num,friends->Data);friends=friends->Next;
		}
		if(start==pause){
			if(!--cen)break;
			pause=EndofV(num);
		}
		temp=temp->Next;
	}
	return num;
}
Vertex EndofV(Vertex V) {
	if(!V)return NULL;
	Vertex temp=V;
	while(temp->Next)temp=temp->Next;
	return temp;
}
Vertex DFS(Vertex V,int n,int key,int deep,Vertex num) {
	num=InsertV(num,key);
	Vertex temp=V[key].Next;
	if(!temp)return num;
//	printf("deep %d.",deep);
if(deep)	for(; temp; temp=temp->Next) {
		num=DFS(V,n,temp->Data,deep-1,num);
	}
	return num;
}
int VisitV(Vertex V,int X){
	while(!V)return 0;
	while(V->Next){
		if(V->Data==X)return X;
		V=V->Next;
	}if(V->Data==X)return X;
	return 0;
}
Vertex CreatV(int num) {
	Vertex V=(Vertex)malloc(sizeof(struct LNode)*num);
	for(int i=0; i<num; i++) {
		V[i].Next=NULL;
		V[i].Data=i;
	}
	return V;
}
Vertex InsertV(Vertex V,int X) {

	Vertex NewV=(Vertex)malloc(sizeof(struct LNode));
	NewV->Data=X;
	NewV->Next=NULL;
	if(!V)return NewV;
	Vertex temp=V;
	while(temp->Next){if(temp->Data==X)return V;temp=temp->Next;
	}
	if(temp->Data==X)return V;
//		printf("[%d]",X);
	temp->Next=NewV;
	return V;
}
