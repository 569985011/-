#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*评测结果
时间	结果	得分	题目	编译器	用时（ms）	内存（MB）	用户
2016-02-10 00:09	答案正确	20	5-1	gcc	18	1	569985011
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）
测试点1	答案正确	12/12		1		1
测试点2	答案正确	2/2			15		1
测试点3	答案正确	2/2			1		1
测试点4	答案正确	2/2			15		1
测试点5	答案正确	2/2			18		1
*/
#define N 100001


int main(){
    int n;
 	scanf("%d",&n);
 	int *a=(int*)malloc(sizeof(int)*n);
// int flag=-1;
// 	for(int i=0;i<n;i++){
// 	
// 		if(flag==-1){
// 			if(a[i]>0)flag=i;
//		 }
//	 }
	 int maxline=0,thisline=0,from=0,to=0,pf=0;
	 for(int i=0;i<n;i++){
	 		scanf("%d",&a[i]);
	 	thisline+=a[i];
	 	if(thisline>maxline){
	 		pf=from;
	 		to=a[i];
//	 		printf("%d ",maxline); 
	 		maxline=thisline;
		 }
		 if(thisline<0){thisline=0;from=a[i];
		 }
	 };
	 
	 printf("%d",maxline);
	 if(!maxline)printf(" %d %d",a[0],a[n-1]);else
	 printf(" %d %d\n",pf,to);


return 0;
}

