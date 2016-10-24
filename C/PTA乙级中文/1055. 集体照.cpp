#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Node;
struct node {
	int High;
	char Name[9];
} a[10001];

int cmp(const void*a,const void*b) {
	Node x=(Node)a;
	Node y=(Node)b;
	if(x->High!=y->High)return x->High-y->High;
	else return strcmp(y->Name,x->Name);
}

void fun(int ,int);

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)scanf("%s%d",a[i].Name,&a[i].High);
	qsort(a,n,sizeof(struct node),cmp);
//for(int i=0;i<n;i++)printf("(%s,%d)",a[i].Name,a[i].High);
	fun((m-1)*(n/m),n);
	for(int i=m-2; i>=0; i--) {
		fun(i*(n/m),(i+1)*(n/m));
	}

	return 0;
}

void fun(int left,int right) {
//	printf("{%d,%d}",left,right);
	int lenth=right-left;
	int flag=0;
	if(lenth%2==0) {
		for(int i=0; i<lenth/2; i++) {
			if(flag)printf(" ");
			else flag=1;
			printf("%s",a[left+i*2].Name);
		}
		for(int i=0; i<lenth/2; i++) {
			if(flag)printf(" ");
			else flag=1;
			printf("%s",a[right-1-i*2].Name);
		}
	} else {
		for(int i=0; i<lenth/2; i++) {
			if(flag)printf(" ");
			else flag=1;
			printf("%s",a[left+1+i*2].Name);
		}
		for(int i=0; i<=lenth/2; i++) {
			if(flag)printf(" ");
			else flag=1;
			printf("%s",a[right-1-i*2].Name);
		}

	}
	printf("\n");
}
