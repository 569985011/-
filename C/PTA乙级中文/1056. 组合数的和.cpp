#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*������
ʱ�� 	��� 	�÷� 	��Ŀ 	���� 	��ʱ(ms) 	�ڴ�(kB) 	�û�
10��25�� 16:05 	����ȷ 	15 	1056 	C (gcc 4.7.2) 	3 	256 	����ţ��
���Ե�
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	2 	256 	9/9
1 	����ȷ 	3 	256 	2/2
2 	����ȷ 	2 	256 	4/4
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

