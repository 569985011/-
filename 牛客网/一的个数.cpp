#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*
]һ�ĸ���
NowCoder�����������Σ����¶�Ҫ�õ�һ���������ԡ�1����������ж��ӡ�
���ݼ��ڣ���Ҳ��ϲ������1����������10��11��12������������ˣ�
��ͬ��ϲ����������а���1��������Ȼ�����а���1�ĸ���Խ����Խϲ����
���ܰ���ͳ��һ��ĳ�������ض��Ľ�����1�ĸ����� 
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

