#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*童年生活二三事
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
NowCoder小时候走路喜欢蹦蹦跳跳，他最喜欢在楼梯上跳来跳去。
但年幼的他一次只能走上一阶或者一下子蹦上两阶。
现在一共有N阶台阶，请你计算一下NowCoder从第0阶到第N阶共有几种走法。
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

