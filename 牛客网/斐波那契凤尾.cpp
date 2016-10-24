// write your code here cpp
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
斐波那契凤尾
时间限制 3000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。

为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。
因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位
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

