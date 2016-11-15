#include <stdio.h>
#include <stdlib.h>
/***********************
* 功能：最大背包问题，修改TestNode中i的取值范围可以规定每样商品的枚举上限 
* 来自：OpenJudge 2016 ACM暑期练习题（已关闭，未检验代码的正确与否） 
* 思路：目前是递归算法。 
*
************************/

typedef struct node *Node;
struct node {
	int W;/* 1<=W<=400 */
	int D;/* 1<=D<=100 */
};

int n;/* 待选商品品种数目 1<=N<=3,402 */
int m;/* 背包最大承重 1<=M<=12,880 */
Node Shop=NULL;/* 待选商品 */
int Max=-1;/* 最后结果 */

void TestNode(int j,int Weight,int Desirability);

int main() {
	scanf("%d%d",&n,&m);
	Shop=(Node)malloc(sizeof(struct node)*n);
	for(int i=0; i<n; i++) {
		scanf("%d%d",&Shop[i].W,&Shop[i].D);
	}
	TestNode(0,0,0);
	printf("%d",Max);
	return 0;
}

void TestNode(int j,int Weight,int Desirability) {
	if(j<n)
		for(int i=0; i<=1; i++) {
			if(Weight+i*Shop[j].W<=m)
				TestNode(j+1,Weight+i*Shop[j].W,Desirability+i*Shop[j].D);
			else
				TestNode(j+1,Weight,Desirability);
		}
	if(Desirability>Max)Max=Desirability;
}


