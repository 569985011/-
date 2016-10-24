#include <stdio.h>
#include <stdlib.h>
#define FULL 101
typedef struct LNode *Vertex;

struct LNode {
	int b,lenth;
	Vertex Next;
};


Vertex InsertV(Vertex,int,int);
Vertex CreatV(int num);

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	Vertex V=CreatV(N+1);
	int a,b,lenth;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&lenth);
		InsertV(&V[a],b,lenth);
		InsertV(&V[b],a,lenth);
	}
	
	for(int i=1;i<N+1;i++){
		BFS
	}
}
Vertex CreatV(int num){
	   Vertex head=(Vertex)malloc(sizeof(struct LNode)*num);
	   for(int i=0;i<num;i++){
	   	head[i].b=i;head[i].lenth=0;head[i].Next=NULL;}
	   	return head;
}
Vertex InsertV(Vertex V,int b,int lenth) {
	Vertex head=V;
	while(V->Next) {
		if(V->Next->lenth>lenth)break;
		if(V->Next->lenth==lenth&&V->Next->b>b)break;
		V=V->Next;
	}
	Vertex New=(Vertex)malloc(sizeof(struct LNode));
	New->lenth=lenth;
	New->b=b;
	New->Next=V->Next;
	V->Next=New;
	return head;
}
