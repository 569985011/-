#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*[�����]�����̷���
��2Xn��һ�������η�����,��һ��1X2�Ĺ�����������,����n ,����̷ŷ���������.
����n=3ʱ,Ϊ2�� 3���񣬹��Ƶ��̷ŷ���������,����ͼ��
ͼ��   http://www.nowcoder.com/questionTerminal/45891d5680e743418faa5accc0544c43

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
		for(int i=min+1;i<=n;i++){//��������̬�������������������ų�������ʱ��Խ��Խ�
								//���ݿ��Խ������ 
	a[i]=a[i-1]+a[i-2];
}
	}
	printf("%lld\n",a[n]);
} 








return 0;
}

