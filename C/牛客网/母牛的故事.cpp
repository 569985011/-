#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
母牛的故事
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？
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

