#include <stdio.h>
#include <stdlib.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-13 23:26	部分正确	17	5-6	gcc	13	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	15/15		1		1
测试点2	答案正确	8/8			1		1
测试点3	答案正确	2/2			1		1
*/
typedef struct LNode *Vertex;
struct LNode {
	int Data;
	int Flag;
	Vertex Next;
};
Vertex CreatV(int);
int InsertV(Vertex,int);
void DFS(Vertex,int,int);
void BFS(Vertex,int,int);
int main() {
	int N,E;
	scanf("%d%d",&N,&E);
	int from,to;
	Vertex V=CreatV(N);
	for(int i=0; i<E; i++) {
		scanf("%d%d",&from,&to);
		InsertV(&V[to],from); 
		InsertV(&V[from],to);
	}
//	for(int i=0; i<N; i++) {
//		printf("%d:",i);
//		Vertex temp=V[i].Next;
//		while(temp) {
//			printf(" %d",temp->Data);
//			temp=temp->Next;
//		}
//		printf("\n");
//	}

	for(int i=0; i<N; i++) {
		if(!V[i].Flag) {
			V[i].Flag=1;
			printf("{");
			printf(" %d",i);
			DFS(V,N,i);
			printf(" }\n");
		}
	}	for(int i=0;i<N;i++)V[i].Flag=0;
	for(int i=0; i<N; i++) {
		if(!V[i].Flag) {
			V[i].Flag=1;
			printf("{");
			printf(" %d",i);
			BFS(V,N,i);
			printf(" }\n");
		}
	}

}
void BFS(Vertex V,int n,int key) {
	int a[10];
	int left=-1,right=0;
	while(left!=right) {
		for(Vertex temp=V[key].Next; temp; temp=temp->Next) {
			int ConFlag=0;
			for(int i=0; i<right%10; i++) {
				if(a[i]==temp->Data) {
					ConFlag=1;
					break;
				}
			}
			if(ConFlag)continue;
			a[right++%10]=temp->Data;
			if(!V[temp->Data].Flag)
			printf(" %d",temp->Data);
			V[temp->Data].Flag=1;
		}
		key=a[++left%10];
	}

}
void DFS(Vertex V,int n,int key) {
	if(!V) {
		return ;
	}
	Vertex temp=V[key].Next;
	while(temp) {
		if(!V[temp->Data].Flag) {
			printf(" %d",temp->Data);
			V[temp->Data].Flag=1;
			DFS(V,n,temp->Data);
		}
		temp=temp->Next;
	}
	return ;
}
Vertex CreatV(int num) {
	Vertex V=(Vertex)malloc(sizeof(struct LNode)*num);
	for(int i=0; i<num; i++) {
		V[i].Next=NULL;
		V[i].Flag=0;
	}
	return V;
}
int InsertV(Vertex V,int X) {
	if(!V)return 0;

	while(V->Next&&V->Next->Data<X)V=V->Next;
	Vertex temp=(V->Next)?V->Next:NULL;
	V->Next=(Vertex)malloc(sizeof(struct LNode));
	V->Next->Data=X;
	V->Next->Next=temp;
//	printf("in%d,",V->Next->Data);
	return 1;
}
