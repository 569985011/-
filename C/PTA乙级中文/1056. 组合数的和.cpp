#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*评测结果
时间 	结果 	得分 	题目 	语言 	用时(ms) 	内存(kB) 	用户
10月25日 16:05 	答案正确 	15 	1056 	C (gcc 4.7.2) 	3 	256 	书生牛犊
测试点
测试点 	结果 	用时(ms) 	内存(kB) 	得分/满分
0 	答案正确 	2 	256 	9/9
1 	答案正确 	3 	256 	2/2
2 	答案正确 	2 	256 	4/4
*/

int main() {
	int n;
	scanf("%d",&n);
	int sum=0,temp;
	for(int i=0;i<n;i++) {
		scanf("%d",&temp);
		sum+=temp;
	}
	
	 printf("%d",sum*11*(n-1));


	return 0;
}

