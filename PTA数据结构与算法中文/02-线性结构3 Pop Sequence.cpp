#include <stdlib.h>
#include <stdio.h>
/*
���Ե�	���	�÷�/���� ��ʱ��ms���ڴ棨MB��Ҫ����ʾ
���Ե�1 ����ȷ  15/15   1  1   sample����һ���Y&N   
���Ե�2 ����ȷ   3/3    2  1   �ﵽ���size�������   
���Ե�3 ����ȷ   2/2    1  1   M==N   
���Ե�4 ����ȷ   2/2    2  1   �����   
���Ե�5 ����ȷ   1/1    1  1   ��С��   
���Ե�6 ����ȷ   2/2    1  1   ����������㷨��ͨ���Ƚϴ�С�жϣ� 
*/


int IsPop(int,int);
int main(){
int m;//��ջ��С 
int n;//���г��� 
int k;//������������ 
scanf("%d%d%d",&m,&n,&k);

for(int i=0;i<k;i++){
	if(IsPop(n,m))printf("YES\n");else printf("NO\n");
}
return 0;
}

int IsPop(int n,int m){
	int temp=1,test;
	int flag=1;
	int *pop=(int*)malloc(sizeof(int)*m);
	pop[0]=1;
	int index=0;
	for(int i=0;i<n;i++){
		scanf("%d",&test);
		if(!flag)continue;
		while(pop[index]!=test){
			pop[++index]=++temp;
			if(index>=m-1)break;
		}
		if(pop[index]==test){
			--index;
		}else{flag=0;
		}
	} 
	return flag;
} 
