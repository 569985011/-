#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*[编程题]骨牌铺方格
在2Xn的一个长方形方格中,用一个1X2的骨牌铺满方格,输入n ,输出铺放方案的总数.
例如n=3时,为2× 3方格，骨牌的铺放方案有三种,如下图：
图见   http://www.nowcoder.com/questionTerminal/45891d5680e743418faa5accc0544c43

1->1;2->2;
*/


int main(){

long long a[91];
a[1]=1;a[2]=2;
a[3]=3;a[4]=5;

int min=4;
int n;

while((scanf("%d",&n))!=EOF){
	if(n>min){
		for(int i=min+1;i<=n;i++){//根据需求动态计算所需结果，并且随着程序运行时间越来越差，
								//数据库会越发完善 
	a[i]=a[i-1]+a[i-2];
}
	}
	printf("%lld\n",a[n]);
} 








return 0;
}

