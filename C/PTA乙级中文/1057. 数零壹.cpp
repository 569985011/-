/*������
ʱ�� 	��� 	�÷� 	��Ŀ 	���� 	��ʱ(ms) 	�ڴ�(kB) 	�û�
10��25�� 16:14 	����ȷ 	20 	1057 	C (gcc 4.7.2) 	5 	384 	����ţ��
���Ե�
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	2 	256 	12/12
1 	����ȷ 	3 	256 	1/1
2 	����ȷ 	5 	384 	1/1
3 	����ȷ 	4 	376 	3/3
4 	����ȷ 	3 	256 	3/3
�鿴����*/
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

