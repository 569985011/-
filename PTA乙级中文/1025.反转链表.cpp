#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*

测试点	结果	用时(ms)	内存(kB)	得分/满分
	0	答案正确	1		204			12/12
	1	段错误		5		8320		0/3
	2	段错误		8		8320		0/2
	3	答案正确	1		256			2/2
	4	答案正确	1		176			2/2
	5	段错误		37		9472		0/3
	6	答案正确	1		296			1/1
error:1*段错误。。。。是循环或递归的错误吧 
1.可能存在多个链表
2.可能存在key大于链表长度
3.可能存在key<1
4.可能存在 链表长度%key==0 

*/
#define N

typedef struct {
	int bef; 
	int data ;
	int next;
} List;
int  fanzhuan(int,const int);
List a[100002];
int main(){

int Address1st;
int n;
int key;
scanf("%d%d%d",&Address1st,&n,&key);

int add,data,next;
for(int i=0;i<n;i++){
	scanf("%d%d%d",&add,&data,&next);
	if(next==-1)next=100001;
	a[add].data=data;
	a[add].next=next;
	a[next].bef=add;
}int head=Address1st;
if(key>1) head=fanzhuan(Address1st,key);
//printf("/********************/\n");
//printf("head %05d %d ",head,a[head].data);
while(head!=100001){
	if(a[head].next!=100001)
	printf("%05d %d %05d\n",head,a[head].data,a[head].next);
	else printf("%05d %d -1\n",head,a[head].data);
	head=a[head].next;
}

return 0;
}
int fanzhuan(int add,const int key){

	int head=add;int i;
	for( i=2;i<=key;i++){
		add=a[add].next;
		if(add==100001)break;	
	}
	if(add==100001)return head;
	
	head=add;
	int ead=a[add].next;
	for(int i=1;i<key;i++){
	a[add].next=a[add].bef;
	
//	printf("--%05d %d %05d\n",add,a[add].data,a[add].next);
	add=a[add].bef;	}
	if(ead==100001)a[add].next=100001;else
	a[add].next=fanzhuan(ead,key);
	
	return head;

		
}
