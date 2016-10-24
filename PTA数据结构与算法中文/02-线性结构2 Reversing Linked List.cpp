#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
测试点结果
测试点	结果	得分/满分 用时（ms）内存（MB）要点提示
测试点1 答案正确  12/12   1  1   sample 有尾巴不反转, 地址取上下界   
测试点2 答案正确   3/3    1  1   正好全反转   
测试点3 答案正确   2/2    1  1   K=N全反转   
测试点4 答案正确   2/2    1  1   K=1不用反转   
测试点5 答案正确   2/2    1  1   N=1 最小case   
测试点6 答案正确   3/3    45 4   最大N,最后剩K-1不反转   
测试点7 答案正确   1/1    2  1   有多余结点不在链表上   

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
