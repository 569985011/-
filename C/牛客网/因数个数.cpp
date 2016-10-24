#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 100000
/*
因子个数
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。
NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。
任意数的因子，首先他是质因数，其次，合数最大的质因数要小于等于（数本身的1/2）由此可知，100000以内的因子最大不大于 
*/
int isprime(int a){
	if(a<2)return 0;
	if(a==2)return 1;
	if(a%2==0)return 0;
	for(int i=3;i<=sqrt(a);i+=2){
		if(a%i==0)return 0;
	}
	return 1;
}


int main(){
    int n;
    int a[N];
    a[0]=2;a[1]=3;a[2]=5;
	int num=2;
    for(int i=5;i<N;i++){
    	if(isprime(i))a[num++]=i;
	}
//	printf("%d",num);经统计，有效数据范围内共有9千多个质数，也就是说，可以成为因子的数就这么多，用这个集合去计算会大大节省时间
//不说多余的，就单是偶数就省去一半了。 
//	for(int i=0;i<num;i++)printf("%d ",a[i]);
	
    while((scanf("%d",&n))!=EOF){
		int cnt=0;
		for(int i=0;i<num;i++){
			if(a[i]>n)break;
			if(n%a[i]==0){
				while(!(n%a[i]))n/=a[i];
			cnt++;	
			}
		}
		printf("%d\n",cnt);
	};
return 0;
}

