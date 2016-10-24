#include <stdio.h>
#include<stdlib.h>
#define FULL 250001
typedef struct node *Node;
typedef struct {
	int Node;
	int Lenth;
} data;
struct node {
	data Reached[501];
	int right;
};


int teams[501];//保存每个结点带有的救援队数目
int Rode[501],Flag_Rode,Num_Rode=0;
int Reached[501];//用于递归路径的缓存
Node Map;//地图

int cmp(const void*a,const void*b) {
	data*x=(data*)a;
	data*y=(data*)b;
	if(x->Lenth!=y->Lenth) {
		return x->Lenth-y->Lenth;
	} else if(teams[x->Node]!=teams[y->Node]) {
		return teams[y->Node]-teams[x->Node];
	} else  return x->Node-y->Node;
}
int DFS(int,int,int,int);

int main() {
	int N,M,S,D;
	scanf("%d%d%d%d",&N,&M,&S,&D);

	Map=(Node)malloc(sizeof(struct node)*N);
	for(int i=0; i<N; i++) {
		Map[i].right=0;
		scanf("%d",&teams[i]);
	}

	while(M--) {
		int a,b,lenth;
		scanf("%d%d%d",&a,&b,&lenth);
		Map[a].Reached[Map[a].right].Node=b;
		Map[a].Reached[Map[a].right++].Lenth=lenth;
		Map[b].Reached[Map[b].right].Node=a;
		Map[b].Reached[Map[b].right++].Lenth =lenth;
	}
	for(int i=0; i<N; i++) {
//		printf("\n%d:",i);
		qsort(Map[i].Reached,Map[i].right,sizeof(data),cmp);
//		for(int j=0;j<Map[i].right;j++){
//			printf("{%d-%d}",Map[i].Reached[j].Node,Map[i].Reached[j].Lenth);
//		}
	}
	int TEAM=DFS(S,D,0,0);
	printf("%d %d\n",Num_Rode,TEAM);
	for(int i=0; i<=Flag_Rode; i++) {
		if(i)printf(" ");
		printf("%d",Rode[i]);
	}
	return 0;
}


int DFS(int a,int b,int Cen,int Lenth) {//还是没解决好不同路径时踩过结点的消除问题。
	static int Result_Lenth= FULL;
	static int Result_Teams=0;

	if(Lenth>Result_Lenth)return Result_Teams;
	Reached[Cen]=a;
	if(a==b) {
		if(Lenth<=Result_Lenth) {
			int ReachedTeam=0;
			for(int i=0; i<=Cen; i++) ReachedTeam+=teams[Reached[i]];
			if(Lenth==Result_Lenth)Num_Rode++;else Num_Rode=1;
			if(Lenth<Result_Lenth||ReachedTeam>Result_Teams) {
				for(int i=0; i<=Cen; i++) {
					Rode[i]=Reached[i];
				}
				Flag_Rode=Cen;
				Result_Teams=ReachedTeam;
				Result_Lenth=Lenth;
				return Result_Teams;
			}
		}
	} else {
		for(int i=0; i<Map[a].right; i++) {
			int flag_Con=0;
			for(int j=0; j<Cen; j++)if(Reached[j]==Map[a].Reached[i].Node) {
					flag_Con=1;
					break;
				}
			if(flag_Con)continue;
			DFS(Map[a].Reached[i].Node,b,Cen+1,Lenth+Map[a].Reached[i].Lenth);
		}

	}


	return Result_Teams;
}

