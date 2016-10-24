#include <stdio.h>
#include <stdlib.h>
/*
评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-15 09:54	部分正确	27	5-7	gcc	14	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	18/18		1		1
测试点2	答案正确	3/3			1		1
测试点3	答案正确	3/3			1		1
测试点4	答案正确	3/3			1		1
测试点5	内存超限	0/3			0		0

*/
typedef struct LNode *Vertex;
struct LNode {
	int Data;
	Vertex Next;
};
Vertex CreatV(int);

void Print(Vertex num,int n);
Vertex InsertV(Vertex,int);
int BFS(Vertex,int,int*);
int N,M;
int main() {
	
	scanf("%d%d",&N,&M);
	int from,to;
	Vertex V=CreatV(N+1);
	for(int i=0; i<M; i++) {
		scanf("%d%d",&from,&to);
		InsertV(&V[from],to);
		InsertV(&V[to],from);
	}
	int*num=(int*)malloc(sizeof(int)*N);
	int cnt;
	for(int i=1; i<=N; i++) {
		printf("%d: ",i);
		cnt=BFS(V,i,num);
		printf("%.2f%%\n",cnt*100.0/N);
	}
}
int BFS(Vertex V,int X,int*visited) {
	visited[0]=X;
	int right=1,left=0,cen=6,pause=0;
	while(left<right&&right<N) {
		Vertex temp=V[visited[left]].Next;
		for(;temp;temp=temp->Next) {
			int i;
			for( i=0; i<right; i++)if(visited[i]==temp->Data)break;
			if(i==right)visited[right++]=temp->Data;
		}
		
		if(left++==pause){
			if(!--cen)break;
			pause=right-1;
		}
	
	}
	return right;
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
	while(temp->Next)temp=temp->Next;
	temp->Next=NewV;
	return V;
}
