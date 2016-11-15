#include <stdio.h>
#include <stdlib.h>
/***********************
* ���ܣ���󱳰����⣬�޸�TestNode��i��ȡֵ��Χ���Թ涨ÿ����Ʒ��ö������ 
* ���ԣ�OpenJudge 2016 ACM������ϰ�⣨�ѹرգ�δ����������ȷ��� 
* ˼·��Ŀǰ�ǵݹ��㷨�� 
*
************************/

typedef struct node *Node;
struct node {
	int W;/* 1<=W<=400 */
	int D;/* 1<=D<=100 */
};

int n;/* ��ѡ��ƷƷ����Ŀ 1<=N<=3,402 */
int m;/* ���������� 1<=M<=12,880 */
Node Shop=NULL;/* ��ѡ��Ʒ */
int Max=-1;/* ����� */

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


