#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*《阳光姐妹淘》，爆裂鼓手 
评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-10 16:41	部分正确	18	5-2	gcc	1	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	12/12		1		1
测试点2	答案正确	4/4			1		1
测试点3	答案错误	0/2			1		1
测试点4	答案正确	2/2			1		1

*/
typedef struct LNode *Pol; // polynomial多项式
struct LNode {
	int coe;//coefficient系数
	int exp;//exponent指数
	Pol next;
};
void PrintP(Pol a);
Pol ReadP(void);
Pol SortP(const Pol);
Pol AddP(const Pol a,const Pol b);
Pol MulP(const Pol a,const Pol b);
int main() {
	Pol a=ReadP();
	Pol b=ReadP();
//	printf("%p ",a);
//	printf("%p",b); 
//	PrintP(a);	printf("\n00****00\n");
//	PrintP(b);	printf("\n00****00\n");
	PrintP(MulP(a,b));
	printf("\n");
	PrintP(AddP(a,b));
//	printf("\n");
	return 0;
}

Pol ReadP(void) {    
	int num;int flag=0; 
	scanf("%d",&num);
	Pol n=(Pol)malloc(sizeof(struct LNode));
	n->next=NULL;
	Pol head=n;
	while(num--) {int k,m;
		scanf("%d%d",&k,&m);
		if(k){ flag=1;
		n->next=(Pol)malloc(sizeof(struct LNode));
		n->next->coe=k;n->next->exp=m;
		n=n->next;} 
	}
	n->next=NULL;
	if(flag)return head->next;else return NULL;
}
Pol AddP(const Pol a1,const Pol b1) {
	if(!a1)return b1;
	if(!b1)return a1;
	Pol a=a1,b=b1,c,head;
	Pol sum=(Pol)malloc(sizeof(struct LNode));
	sum->coe=0;
	head=sum;
while(a||b){
	if(!a){c=b;b=b->next;}else
	if(!b||b->exp<=a->exp){c=a;a=a->next;}else {c=b;b=b->next;
	}
//	printf("1"); 
	if(0==sum->coe||sum->exp==c->exp){
		sum->exp=c->exp;sum->coe+=c->coe;
	}else {sum=sum->next;sum->coe=c->coe;sum->exp=c->exp;
	}sum->next=(Pol)malloc(sizeof(struct LNode));
//	printf("2");
}sum->next=NULL;
		head=SortP(head);
	return head;
}
Pol MulP(const Pol a1,const Pol b1) { // Multiplication乘法
	Pol sum=NULL;
	if(!a1||!b1)return sum;
	Pol a=a1,b=b1;
	while(a){
		Pol c=(Pol)malloc(sizeof(struct LNode));//头结点设为空 
		c->coe=0; 
		while(b){
			c->next=(Pol)malloc(sizeof(struct LNode));
			c->next->coe=b->coe*a->coe;
			c->next->exp=b->exp+a->exp;
			c=c->next;
		}c->next=NULL;
		sum=AddP(sum,c->next);
	}
	return sum;
}
Pol SortP(Pol head){
	if(!head)return NULL;
	Pol a=head,b;
	for(;a;a=a->next){
		b=a;
		for(;b->next;b=b->next){
			
			if(b->next->exp==a->exp){//合并同类项 
				a->coe+=b->next->coe;
				b->next=b->next->next;
			}else if(b->next->exp>a->exp){//降序排列； 
				int exp=a->exp;
				int coe=a->coe;
				a->coe=b->next->coe;
				a->exp=b->next->exp;
				b->next->exp=exp;
				b->next->coe=coe;
			}else if(a->coe==0){//清除零项 
				a->coe=b->next->coe;
				a->exp=b->next->exp;
				b->next=b->next->next;
			}b=b->next;
		}
	}
	return head;
}
void PrintP(Pol a) {
	int flag=0;
	if(!a){printf("0 0");return ;
	}

	for(;a;a=a->next){
//		if(a->coe==0)continue;/*加上这句话用例3就错了，删掉用例2就错了*/
		if(flag)printf(" ");
		else flag=1;
		printf("%d %d",a->coe,a->exp);
		
	}
}
