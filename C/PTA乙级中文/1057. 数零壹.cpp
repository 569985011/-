/*评测结果
时间 	结果 	得分 	题目 	语言 	用时(ms) 	内存(kB) 	用户
10月25日 16:14 	答案正确 	20 	1057 	C (gcc 4.7.2) 	5 	384 	书生牛犊
测试点
测试点 	结果 	用时(ms) 	内存(kB) 	得分/满分
0 	答案正确 	2 	256 	12/12
1 	答案正确 	3 	256 	1/1
2 	答案正确 	5 	384 	1/1
3 	答案正确 	4 	376 	3/3
4 	答案正确 	3 	256 	3/3
查看代码*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100001

int main() {
	char word[MaxSize];
	gets(word);

	int sum=0;
	for(char*p=word; *p!='\0'; p++) {
		if(*p>='a'&&*p<='z')
			sum+=*p-'a'+1;

		if(*p>='A'&&*p<='Z')
			sum+=*p-'A'+1;
	}
//printf("{%d}",sum);
	int Result[2]={0};
	while(sum){
		Result[sum%2]++;
		sum/=2;
	}
printf("%d %d",Result[0],Result[1]);
	return 0;
}

