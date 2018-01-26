#include <stdio.h>
#include<stdlib.h>
#define FULL 250001
/*
提交时间	状态	分数	题目	编译器	耗时	用户
2018/1/23 11:57:04	答案正确	25	7-35	C (gcc)	238 ms	569985011
测试点	提示	结果	耗时	内存
0	sample	答案正确	2 ms	240KB
1	5条不同的最短路	答案正确	2 ms	244KB
2	最小N和M	答案正确	2 ms	156KB
3	最大N和M，随机数据构成完全图	答案正确	238 ms	2196KB
*/
typedef struct node *Node;
typedef struct {
	int Node;//目标结点
	int Lenth;//边长
} data;
struct node {
	data Reached[501];//与之有边连接的结点集合
	int right;//集合里的结点个数
};

int teams[501];//保存每个结点带有的救援队数目
int Lenth[501][3];//[0]记录从起点出发到各结点的路径长度 ;[1]记录该路径能获取的救援队总数；【2】记录等长路径条数
Node Map;//地图

int cmp(const void*a,const void*b) {//
	data*x=(data*)a;
	data*y=(data*)b;
	if(x->Lenth!=y->Lenth) {
		return x->Lenth-y->Lenth;
	} else if(teams[x->Node]!=teams[y->Node]) {
		return teams[y->Node]-teams[x->Node];
	} else  return teams[x->Node]-teams[y->Node];
}

void Dijkstra(int);
void DFS(int,const int);
int main() {
	int N,M,S,D;//结点数、边数、起点、终点
	scanf("%d%d%d%d",&N,&M,&S,&D);

	Map=(Node)malloc(sizeof(struct node)*N);//初始化地图上的结点
	for(int i=0; i<N; Map[i++].right=0);

	for(int i=0; i<N; scanf("%d",&teams[i++]));//读入每个结点的价值——城市拥有的救援队数量

	{
		//读入地图信息，并排序整理
		while(M--) {
			int a,b,lenth;
			scanf("%d%d%d",&a,&b,&lenth);
			Map[a].Reached[Map[a].right].Node=b;
			Map[a].Reached[Map[a].right++].Lenth=lenth;
			Map[b].Reached[Map[b].right].Node=a;
			Map[b].Reached[Map[b].right++].Lenth =lenth;
		}
		for(int i=0; i<N; i++) {
//			printf("\n%d:",i);
			qsort(Map[i].Reached,Map[i].right,sizeof(data),cmp);
			for(int j=0; j<Map[i].right; j++) {
//				printf("{%d-%d}",Map[i].Reached[j].Node,Map[i].Reached[j].Lenth);
			}
		}
	}

	for(int i=0; i<N; Lenth[i++][0]=FULL); //[0]初始化设定从起点到所有其他结点的路径长度为无穷;
	Lenth[S][0]=0;
	Lenth[S][1]=teams[S];
	Dijkstra(S);
	printf("%d %d\n",Lenth[D][2],Lenth[D][1]);
	DFS(D,S);
	printf("%d",D);
	return 0;
}


void Dijkstra(int a) {//戴克斯特拉算法

	for(int i=0; i<Map[a].right; i++) {
		data temp=Map[a].Reached[i];
		if(Lenth[a][0]+temp.Lenth<Lenth[temp.Node][0]) {
			Lenth[temp.Node][0]=Lenth[a][0]+temp.Lenth;
			Lenth[temp.Node][1]=Lenth[a][1]+teams[temp.Node];
			Lenth[temp.Node][2]=1;
			Dijkstra(temp.Node);
		} else if(Lenth[a][0]+temp.Lenth==Lenth[temp.Node][0]) {
			if(Lenth[a][1]+teams[temp.Node]>Lenth[temp.Node][1]) {
				Lenth[temp.Node][1]=Lenth[a][1]+teams[temp.Node];
			}
			++Lenth[temp.Node][2];
			Dijkstra(temp.Node);
		}
	}

}

void DFS(int dd,const int S) {//深度优先，从终点递归回溯， 如果存在某个结点：它到终点的边长加上它到起点的长度== 终点到原点的长度&&它到起点的救援队数量+终点的救援队数量== 起点到终点的救援队数量，那么这个结点一定是最短路上的一个结点。
	if(dd==S)return;
	for(int i=0; i<Map[dd].right; i++) {
		data temp=Map[dd].Reached[i];
		if(Lenth[temp.Node][0]+temp.Lenth==Lenth[dd][0]&&
		        Lenth[temp.Node][1]+teams[dd]==Lenth[dd][1]) {
//			printf("*");
			DFS(temp.Node,S);
			printf("%d ",temp.Node);
		}
	}
}

