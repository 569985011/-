#include <stdlib.h>
#include <stdio.h>
/*

  
  2016-02-28 15:00    ����ȷ      25    01-���Ӷ�2  gcc  3  1  569985011  
  
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��	Ҫ����ʾ 
���Ե�1	����ȷ   13/13  1  	1   sample��1�����֡���������������ͷ��β���в�������   
���Ե�2 ����ȷ   2/2    1  	1   �����������и���   
���Ե�3 ����ȷ   2/2    1  	1   ���кͶ�Ӧ��ͬi���ǲ�ͬj����β��0   
���Ե�4 ����ȷ   2/2    1  	1   1������   
���Ե�5 ����ȷ   2/2    2  	1   ȫ�Ǹ���   
���Ե�6 ����ȷ   2/2    1  	1 	������0   
���Ե�7 ����ȷ   1/1    1 	 1  ����ǰ����һ����0   
���Ե�8 ����ȷ   1/1    3  	1   ���N    
*/



int main(){
	int n;
scanf("%d",&n);
int*a=(int*)malloc(sizeof(int)*n);
int maxsum=0,thissum=0,from=0,maxfrom=0,end=n-1;
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	thissum+=a[i];
	if(thissum>maxsum||(!maxsum&&!thissum)){
		maxfrom=from;
		end=i;
		maxsum=thissum;
	}
	if(thissum<0){
		thissum=0;
		from=i+1;
	}
}
printf("%d %d %d",maxsum,a[maxfrom],a[end]);

return 0;
}


