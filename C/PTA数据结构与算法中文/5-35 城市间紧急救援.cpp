#include <stdio.h>
#include<stdlib.h>
#define FULL 250001
/*
�ύʱ��	״̬	����	��Ŀ	������	��ʱ	�û�
2018/1/23 11:57:04	����ȷ	25	7-35	C (gcc)	238 ms	569985011
���Ե�	��ʾ	���	��ʱ	�ڴ�
0	sample	����ȷ	2 ms	240KB
1	5����ͬ�����·	����ȷ	2 ms	244KB
2	��СN��M	����ȷ	2 ms	156KB
3	���N��M��������ݹ�����ȫͼ	����ȷ	238 ms	2196KB
*/
typedef struct node *Node;
typedef struct {
	int Node;//Ŀ����
	int Lenth;//�߳�
} data;
struct node {
	data Reached[501];//��֮�б����ӵĽ�㼯��
	int right;//������Ľ�����
};

int teams[501];//����ÿ�������еľ�Ԯ����Ŀ
int Lenth[501][3];//[0]��¼����������������·������ ;[1]��¼��·���ܻ�ȡ�ľ�Ԯ����������2����¼�ȳ�·������
Node Map;//��ͼ

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
	int N,M,S,D;//���������������㡢�յ�
	scanf("%d%d%d%d",&N,&M,&S,&D);

	Map=(Node)malloc(sizeof(struct node)*N);//��ʼ����ͼ�ϵĽ��
	for(int i=0; i<N; Map[i++].right=0);

	for(int i=0; i<N; scanf("%d",&teams[i++]));//����ÿ�����ļ�ֵ��������ӵ�еľ�Ԯ������

	{
		//�����ͼ��Ϣ������������
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

	for(int i=0; i<N; Lenth[i++][0]=FULL); //[0]��ʼ���趨����㵽������������·������Ϊ����;
	Lenth[S][0]=0;
	Lenth[S][1]=teams[S];
	Dijkstra(S);
	printf("%d %d\n",Lenth[D][2],Lenth[D][1]);
	DFS(D,S);
	printf("%d",D);
	return 0;
}


void Dijkstra(int a) {//����˹�����㷨

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

void DFS(int dd,const int S) {//������ȣ����յ�ݹ���ݣ� �������ĳ����㣺�����յ�ı߳������������ĳ���== �յ㵽ԭ��ĳ���&&�������ľ�Ԯ������+�յ�ľ�Ԯ������== ��㵽�յ�ľ�Ԯ����������ô������һ�������·�ϵ�һ����㡣
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

