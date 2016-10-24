#include <stdlib.h>
#include <stdio.h>



int main(){
    int n;  long long a,b;
   int u[8];
 	while((scanf("%lld%lld",&a,&b))!=EOF){
 		int flag=0;
 		long long sum=a+b;int i=0;
 		if(sum<0){sum*=-1;flag=1;
		 }if(!sum)printf("0");
 		while(sum){
 			u[i++]=sum%10;
 			sum/=10;
		 }if(flag)printf("-");
		 for(int j=i-1;j>=0;j--){
		 	printf("%d",u[j]);if(j%3==0&&j)printf(",");
		 }
 	 printf("\n");

 };


return 0;
}

