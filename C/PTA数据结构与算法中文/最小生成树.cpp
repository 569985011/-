#include <stdio.h>
#include <stdlib.h>
#define FULL 101
typedef struct LNode *Vertex;

struct LNode {
	int b,lenth;
	Vertex Next;
};

Vertex CreatV(int);
void FreeV(Vertex,int);
int Prim(Vertex,int);
Vertex InsertV(Vertex,int,int);

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	Vertex V=CreatV(N+1);
	for(int i=0; i<M; i++) {
		int from,to,lenth;
		scanf("%d%d%d",&from,&to,&lenth);
		InsertV(&V[to],from,lenth);
		InsertV(&V[from],to,lenth);
	}
	int lenth=Prim(V,N+1);
	printf("%d",lenth);
	return 0;
}
int Prim(Vertex V,int n) {
	int lenth=0;
	int min=0;
	for(int i=1; i<n; i++) {
		if(V[i].Next)
			if(V[i].Next->lenth<V[min].Next->lenth)min=i;
	}
	int*a=(int*)malloc(sizeof(int)*n-1),right=1;
	a[0]=min;
	lenth+=V[min].Next->lenth;
	a[right++]=V[min].Next->b;
	FreeV(V,a[0]);
	while(right<n-1) {
		min=-1;
		for(int i=0; i<right; i++) {
			if(V[a[i]].Next){
				if(min!=-1){
					if(V[a[i]].Next->lenth<V[a[min]].Next->lenth)min=i;
				}else min=i;
				
			}
		}
		if(min==-1)return 0;
		int i;
		for(i=0; i<right; i++)
			if(a[i]==V[a[min]].Next->b)break;
		if(i==right) {
			a[right++]=V[a[min]].Next->b;
			lenth+=V[a[min]].Next->lenth;
		}
		FreeV(V,a[min]);
	}
	printf("%d ",a[0]);
	return lenth;
}
void FreeV(Vertex V,int X) {
	Vertex temp=V[X].Next;
	V[X].Next=temp->Next;
	X=temp->b;
	free(temp);
	temp=V[X].Next;
	V[X].Next=temp->Next;
	free(temp);
}
Vertex CreatV(int num) {
	Vertex V=(Vertex)malloc(sizeof(struct LNode)*num);
	for(int i=0; i<num; i++) {
		V[i].Next=NULL;
		V[i].b=0;
		V[i].lenth=0;
	}
	V[0].Next=(Vertex)malloc(sizeof(struct LNode));
	V[0].Next->b=0;
	V[0].Next->lenth=FULL;
	V[0].Next->Next=NULL;
	return V;
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
