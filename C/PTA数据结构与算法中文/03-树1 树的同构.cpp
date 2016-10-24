#include <stdlib.h>
#include <stdio.h>
/*������
2016-03-12 23:55    ����ȷ      25    03-��1  gcc  13  1  569985011  
  ���Ե��� 
���Ե�  ���	�÷�/������ʱ��ms���ڴ棨MB��Ҫ����ʾ
���Ե�1 ����ȷ   7/7    1  1   sample 1 ��˫�߻������߻����ڵ��Ų�ͬ������ͬ   
���Ե�2 ����ȷ   7/7    1  1   sample 2 ��3�㿪ʼ��ÿ�������ݶԣ�������㲻��   
���Ե�3 ����ȷ   3/3    1  1   �������ͬ   
���Ե�4 ����ȷ   2/2    1  1   ����   
���Ե�5 ����ȷ   3/3    13 1   ֻ��1����㣬�ṹͬ�����ݲ�ͬ   
���Ե�6 ����ȷ   3/3    1  1   ���N��������������ͬ��������ͬ 

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
