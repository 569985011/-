#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/* 评测结果 时间 	结果 	得分 	题目 	编译器 	用时（ms） 	内存（MB） 	用户
2016-08-30 10:31 	全部正确 	25 	5-27 	gcc 	1 	1 	569985011
测试点结果 测试点 	结果 	得分/满分 	用时（ms） 	内存（MB）
测试点1 	答案正确 	18/18 	1 	1
测试点2 	答案正确 	2/2 	1 	1
测试点3 	答案正确 	5/5 	1 	1
测试点4 	答案正确 	5/5 	1 	1
查看代码*/
typedef struct node *Node;
struct node {
	char Name[11];
	int space;
	int  Parant;
};

Node Tree;
int n;

int Scan(char*);
int Trace(int);
int judgeParent(int,int);//父子
int judgeSibling(int,int);//兄弟
int judgeAncestor(int,int);//祖先
void work();
int Index(char*);

int main() {
	int m;
	scanf("%d%d",&n,&m);
	Tree=(Node)malloc(sizeof(struct node)*n);
	getchar();//清除缓存
	for(int i=0; i<n; i++) {
		Tree[i].space=Scan(Tree[i].Name);
		Tree[i].Parant=i;
	}
	Tree[0].Parant=-1;

	for(int i=0; i<m; i++) {
		work();
		getchar();
	}

	return 0;
}
int judgeParent(int x,int y) {
	if(Tree[x].Parant==x)Tree[x].Parant=Trace(x);
	return Tree[x].Parant==y;
}
int judgeSibling(int x,int y) {
	if(Tree[x].Parant==x)Tree[x].Parant=Trace(x);
	if(Tree[y].Parant==y)Tree[y].Parant=Trace(y);
	return Tree[x].Parant==Tree[y].Parant;
}
int judgeAncestor(int x,int y) {
	while(x!=-1) {
		if(judgeParent(x,y))return 1;
		else x=Tree[x].Parant;
	}
	return 0;
}

void work() {
	char StrX[11],StrY[11],relation[11];
	scanf("%s%*s%*s%s%*s%s",StrX,relation,StrY);
//	printf("%s - %s - %s\n",StrX,relation,StrY);

	int X=Index(StrX);
	int Y=Index(StrY);
//	printf("%d   -    %d",X,Y);
	int result;
	switch(relation[0]) {
		case 'c':
			result=judgeParent(X,Y);
			break;
		case 'p':
			result=judgeParent(Y,X);
			break;
		case 's':
			result=judgeSibling(X,Y);
			break;
		case 'd':
			result=judgeAncestor(X,Y);
			break;
		case 'a':
			result=judgeAncestor(Y,X);
			break;
		default:
			result=-1;
			break;
	}



	if(result==1)printf("True\n");
	else if(!result)printf("False\n");
//	else printf("ERROR:系统不能识别所指定关系！\n");
}


int Index(char*a) {
	for(int i=0; i<n; i++) {
//		printf("*");
		if(strcmp(Tree[i].Name,a)==0)return i;
	}
// 	printf("ERROR:所给人名不存在！\n");
	return -1;
}

int Trace(int child) { //往前遍历第一个比他缩进少的就是他的父亲

	for(int i=child-1; i>=0; i--) {
		if(Tree[i].space<Tree[child].space) {
//		printf("%d's parent is %d'",child,i);
			return i;
		}
	}
	return -1;//如果没有，那么他就是亚当夏娃了。
}

int Scan(char*p) {
	char c;
	int space=0;

	while((c=getchar())==' ')space++;//记录字符串前面的空格数量

	do {
		*p++=c;
	} while((c=getchar())!='\n');
	*p='\0';

	return space;
}
