#include<stdio.h>

#define N
int ya(int*sum,int*cnt){


if(*sum==2&&*cnt==7)return *sum;
	else if(*sum<2||*cnt>7)return -1;
	else if(*sum%2!=0)return -1;
	else {*sum=(*sum)/2-1;*cnt+=1;
	ya(sum,cnt);
}}
int main()
{
int sum,cnt=1;int flag=0;
int *p=&sum,*q=&cnt;int i;
	for (i=0; 1;){
		sum=i;cnt=0;
		flag=ya(&sum,&cnt);
		if(flag==-1){i++;}
		else if(cnt==7&&sum==2)break;
	}
	printf("sum=%d\n",i);sum=i;
	for(int j=0;j<7;j++){
		//if(j)printf(",");

		i=sum/2+1;
		sum=sum-i;
		printf("sell=%d,",i);

	}printf("\n");

return 0;
}

