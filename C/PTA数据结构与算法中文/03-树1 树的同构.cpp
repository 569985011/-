#include <stdlib.h>
#include <stdio.h>
/*评测结果
2016-03-12 23:55    答案正确      25    03-树1  gcc  13  1  569985011  
  测试点结果 
测试点  结果	得分/满分用时（ms）内存（MB）要点提示
测试点1 答案正确   7/7    1  1   sample 1 有双边换、单边换，节点编号不同但数据同   
测试点2 答案正确   7/7    1  1   sample 2 第3层开始错，每层结点数据对，但父结点不对   
测试点3 答案正确   3/3    1  1   结点数不同   
测试点4 答案正确   2/2    1  1   空树   
测试点5 答案正确   3/3    13 1   只有1个结点，结构同但数据不同   
测试点6 答案正确   3/3    1  1   最大N，层序遍历结果相同，但树不同 

*/
typedef struct TNode{
int left;int right;
char data;	
}*BTree;


int char2int(char);
BTree ReadT(int);
int FindT(char,BTree,int);
int CompareT(BTree ,int,BTree ,int);

int main(){
	int n;scanf("%d",&n); 
  BTree a=ReadT(n);
  int m;scanf("%d",&m);
  BTree b=ReadT(m);
  if(m!=n){printf("No\n");/*printf("1");*/
  }else{int flag=1;
  for(int i=0;i<n;i++){/*printf("*");*/
  	int t=FindT(a[i].data,b,m);if(t==-1){flag=0;break;/**/ }
  	flag=(CompareT(a,a[i].left,b,b[t].left)||CompareT(a,a[i].left,b,b[t].right));if(!flag){/*printf("4");*/break;
	  }
  	flag=(CompareT(a,a[i].right,b,b[t].left)||CompareT(a,a[i].right,b,b[t].right));if(!flag){/*printf("3");*/
	  break;}
  }
  if(flag)printf("Yes\n");else printf("No\n");
  }
  
return 0;
}
int CompareT(BTree a,int i,BTree b,int j){
	if(i==-1||j==-1)if(i==j)return 1;else return 0;
	
	if(a[i].data!=b[j].data)return 0;else return 1;	
}
int char2int(char c){
	if(c>='0'&&c<='9')return c-'0';
	return -1;
}
int FindT(char c,BTree h,int Size){
	for(int i=0;i<Size;i++){
		if(h[i].data==c)return i;
	}
	return -1;
}
BTree ReadT(int num){
		BTree c=(BTree )malloc(sizeof(struct TNode)*num);	
			char left,right;
	for(int i=0;i<num;i++){

		scanf(" %C %c %c",&c[i].data,&left,&right);
		c[i].left=char2int(left);
		c[i].right=char2int(right);
//		printf("%c-%d-%d\n",c[i].data,c[i].left,c[i].right); 
	}
	return c;
}
