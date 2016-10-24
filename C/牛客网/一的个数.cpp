#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*
]一的个数
NowCoder总是力争上游，凡事都要拿第一，所以他对“1”这个数情有独钟。
爱屋及乌，他也很喜欢包含1的数，例如10、11、12……。不仅如此，
他同样喜欢任意进制中包含1的数。当然，其中包含1的个数越多他越喜欢。
你能帮他统计一下某个数在特定的进制下1的个数吗？ 
*/

int main(){
    long long n;
	int r;
    while((scanf("%ld%d",&n,&r))!=EOF){
    	int cnt=0;
		while(n){
    		if(n%r==1)cnt++;
			n/=r;
		}
	printf("%d\n",cnt);
	}	;










return 0;
}

