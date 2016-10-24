#include <stdlib.h>
#include <stdio.h>
/*

  
  2016-02-28 15:00    答案正确      25    01-复杂度2  gcc  3  1  569985011  
  
测试点结果
测试点	结果	得分/满分	用时（ms）	内存（MB）	要点提示 
测试点1	答案正确   13/13  1  	1   sample换1个数字。有正负，负数开头结尾，有并列最大和   
测试点2 答案正确   2/2    1  	1   最大和序列中有负数   
测试点3 答案正确   2/2    1  	1   并列和对应相同i但是不同j，即尾是0   
测试点4 答案正确   2/2    1  	1   1个正数   
测试点5 答案正确   2/2    2  	1   全是负数   
测试点6 答案正确   2/2    1  	1 	负数和0   
测试点7 答案正确   1/1    1 	 1  最大和前面有一段是0   
测试点8 答案正确   1/1    3  	1   最大N    
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


