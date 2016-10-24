#include<stdio.h>
#include<stdlib.h>
/*
  2016-03-13 00:47    答案正确      25    03-树2  gcc  1  1  569985011  
  
测试点  结果    得分/满分用时（ms）内存（MB）要点提示
测试点1 答案正确  13/13   1  1   sample 编号乱序，有单边左孩子，中间层少先输出   
测试点2 答案正确   5/5    1  1   最大N，有单边右孩子，多层   
测试点3 答案正确   1/1    1  1   最小N   
测试点4 答案正确   5/5    1  1   每层都有输出，有双孩子   
测试点5 答案正确   1/1    1  1   单边树，只有1个输出 
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
	int a[10];//同一时刻数组最大容量 
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
