#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
���Ե���
���Ե�	���	�÷�/���� ��ʱ��ms���ڴ棨MB��Ҫ����ʾ
���Ե�1 ����ȷ  12/12   1  1   sample ��β�Ͳ���ת, ��ַȡ���½�   
���Ե�2 ����ȷ   3/3    1  1   ����ȫ��ת   
���Ե�3 ����ȷ   2/2    1  1   K=Nȫ��ת   
���Ե�4 ����ȷ   2/2    1  1   K=1���÷�ת   
���Ե�5 ����ȷ   2/2    1  1   N=1 ��Сcase   
���Ե�6 ����ȷ   3/3    45 4   ���N,���ʣK-1����ת   
���Ե�7 ����ȷ   1/1    2  1   �ж����㲻��������   

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
