#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*ͯ�����������
ʱ������ 1000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
NowCoderСʱ����·ϲ���ı�����������ϲ����¥����������ȥ��
�����׵���һ��ֻ������һ�׻���һ���ӱ������ס�
����һ����N��̨�ף��������һ��NowCoder�ӵ�0�׵���N�׹��м����߷���
*/
int fun(int n){
	if(n==1)return 1;
	if(n==2)return 2;
	else return fun(n-1)+fun(n-2);
}

int main(){
long long a[91];
a[1]=1;a[2]=2;
for(int i=3;i<91;i++){
	a[i]=a[i-1]+a[i-2];
}

int n;
while((scanf("%d",&n))!=EOF){
	printf("%lld\n",a[n]);
}








return 0;
}

