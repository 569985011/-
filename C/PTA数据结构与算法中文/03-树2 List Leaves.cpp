#include<stdio.h>
#include<stdlib.h>
/*
  2016-03-13 00:47    ����ȷ      25    03-��2  gcc  1  1  569985011  
  
���Ե�  ���    �÷�/������ʱ��ms���ڴ棨MB��Ҫ����ʾ
���Ե�1 ����ȷ  13/13   1  1   sample ��������е������ӣ��м���������   
���Ե�2 ����ȷ   5/5    1  1   ���N���е����Һ��ӣ����   
���Ե�3 ����ȷ   1/1    1  1   ��СN   
���Ե�4 ����ȷ   5/5    1  1   ÿ�㶼���������˫����   
���Ե�5 ����ȷ   1/1    1  1   ��������ֻ��1����� 
*/
typedef struct TNode{
int Left;int Right;
}*BTree;

void LevelorderTraversal( BTree BT ,int i);
int char2int(char c);
BTree ReadT(int num);

int main(){
	int n;
scanf("%d",&n);

BTree T=ReadT(n);
if(n<=1){printf("0");return 0;
}
int head=-1;
for(int i=0;i<n;i++){
	if(T[i].Left >=0||T[i].Right >=0){
		head=i;
		for(int j=0;j<n;j++){
			if(T[j].Left ==i||T[j].Right ==i){head=-1;break;
			} 
		}
		if(head!=-1)break;
	}
}
//printf("head=%d ",head);
LevelorderTraversal( T,head);



return 0;
}
void LevelorderTraversal( BTree T,int i ) {
	if(!T)return ;
	int a[10];//ͬһʱ������������� 
	int left=-1,right=0,flag=0;
	a[0]=i;
	while(left!=right){
		BTree temp=&T[a[++left]];
		if(temp->Left >=0){
			int j;
			for( j=0;j<right;j++){
				if(a[j]==temp->Left )break;
			}
			if(j>=right)a[++right%10]=temp->Left;
		}
		if(temp->Right >=0){
			int j;
			for( j=0;j<right;j++){
				if(a[j]==temp->Right  )break;
			}
			if(j>=right)a[++right%10]=temp->Right ;
		}else if(temp->Left <0){
//			printf("??");
			if(flag)printf(" ");else flag=1;
			printf("%d",a[left]);
		}
	}
//	printf("end");

}
int char2int(char c){
	if(c>='0'&&c<='9')return c-'0';
	return -1;
}
BTree ReadT(int num){
		BTree c=(BTree )malloc(sizeof(struct TNode)*num);	
			char left,right;
	for(int i=0;i<num;i++){

		scanf(" %c %c",&left,&right);
	
		c[i].Left=char2int(left);
		c[i].Right=char2int(right);

	}
	return c;
}
