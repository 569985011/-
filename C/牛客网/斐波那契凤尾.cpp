// write your code here cpp
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
쳲�������β
ʱ������ 3000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
NowCoder�ų��Լ��Ѿ���ס��1-100000֮�����е�쳲���������

Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ�
��ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ
*/
#define N 100001


int main(){

int a[N];
a[1]=1;
a[2]=2;
int min=2;int n;
for(int i=3;i<=100000;i++){
			a[i]=(a[i-1]+a[i-2]);
    if(a[i]>=1000000)a[i]-=1000000;} 
while((scanf("%d",&n))!=EOF){
	
	if(n<25)printf("%d\n",a[n]);else printf("%06d\n",a[n]);
}







return 0;
}

