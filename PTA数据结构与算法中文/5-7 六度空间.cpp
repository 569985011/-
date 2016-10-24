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
测试点4	答案正确	3/3			14		1
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
Vertex EndofV(Vertex);
Vertex DFS(Vertex,int,int,int,Vertex);//深度优先搜索
Vertex BFS(Vertex);

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	int from,to;
	Vertex V=CreatV(N+1);
	for(int i=0; i<M; i++) {
		scanf("%d%d",&from,&to);
		InsertV(&V[to],from);
		InsertV(&V[from],to);
	}

	for(int i=1; i<N+1; i++) {
		printf("%d: ",i);
		Vertex num=DFS(V,N,i,6,NULL);//深度优先
//		Vertex num=BFS(&V[i]);
		Print(num,N);
		free(num);
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
		printf("%d ",num->Data);
	}
//	printf(" }\n");

	printf("%.2f%%\n",cnt*100.0/n);
}
Vertex BFS(Vertex V) {
	if(!V)return 0;
	int cen=6;
	Vertex num=InsertV(NULL,V->Data);
	Vertex temp=num;
	Vertex start,pause=num,end;
	while(temp) {
		start=temp;
		printf("(%X)",start);
		Vertex friends=V[temp->Data].Next;
		while(friends) {
			printf("/");
			num=InsertV(num,friends->Data);
			friends=friends->Next;
		}
		end=EndofV(num);
		printf("*");
		if(start==pause) {
			if(!--cen)return num;
			pause=end;
		}
		temp=temp->Next;printf("{%X}",temp);
	}printf("break;") ;
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
if(deep>1)	for(; temp; temp=temp->Next) {
		num=DFS(V,n,temp->Data,deep-1,num);
	}
	return num;
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
		
	temp->Next=NewV;printf("[%d]",X);
	return V;
}
