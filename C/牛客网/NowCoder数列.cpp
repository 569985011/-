#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000
/*观察可知以八个数据为循环， 
0	7	1
1	11	2
2	18	0
3	29	2
4	47	2
5	76	1
6	123	0
7	199	1
*/


int main() {
//	long a[N];
//	a[0]=7;
//	a[1]=11;
//	int min=1;char c;
	long n;
//	scanf("%d",&min);
//	printf("111");
	 while((scanf("%ld",&n))!=EOF){
		if(n%4==2)
		printf("Yes\n");else
			printf("No\n");
	}
	return 0;
}



