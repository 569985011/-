#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
ĸţ�Ĺ���
ʱ������ 1000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
��һͷĸţ����ÿ�������һͷСĸţ��ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ��
����ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��
*/


int main(){

 int a[55],b[55],c[55],d[55];
    a[1]=0;b[1]=1;c[1]=0;d[1]=0;
    a[2]=1;b[2]=0;c[2]=0;d[2]=1;
    a[3]=1;b[3]=0;c[3]=1;d[3]=1;
    a[4]=1;b[4]=1;c[4]=1;d[4]=1;
    int min=4;
    int n;
    while((scanf("%d",&n))!=EOF){
        if(n>min){
            for(int i=min+1;i<=n;i++){
                c[i]=d[i-1];
                b[i]=c[i-1];
                a[i]=b[i-1]+a[i-1];
                d[i]=a[i];
            }
        }
        printf("%d\n",a[n]+b[n]+c[n]+d[n]);
    }








return 0;
}

