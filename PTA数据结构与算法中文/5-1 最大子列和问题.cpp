#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-10 00:09	����ȷ	20	5-1	gcc	18	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	12/12		1		1
���Ե�2	����ȷ	2/2			15		1
���Ե�3	����ȷ	2/2			1		1
���Ե�4	����ȷ	2/2			15		1
���Ե�5	����ȷ	2/2			18		1
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

