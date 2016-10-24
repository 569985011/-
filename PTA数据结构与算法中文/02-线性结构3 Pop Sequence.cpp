#include <stdlib.h>
#include <stdio.h>
/*
测试点	结果	得分/满分 用时（ms）内存（MB）要点提示
测试点1 答案正确  15/15   1  1   sample乱序，一般的Y&N   
测试点2 答案正确   3/3    2  1   达到最大size后又溢出   
测试点3 答案正确   2/2    1  1   M==N   
测试点4 答案正确   2/2    2  1   最大数   
测试点5 答案正确   1/1    1  1   最小数   
测试点6 答案正确   2/2    1  1   卡特殊错误算法（通过比较大小判断） 
*/


int IsPop(int,int);
int main(){
int m;//堆栈大小 
int n;//数列长度 
int k;//测试用例个数 
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
