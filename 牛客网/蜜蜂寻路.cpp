#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
蜜蜂寻路
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
nowcoder利用业余时间养了一窝蜜蜂，因为空间比较小，蜂房只有两排，如下图所示：
(图见  http://uploadfiles.nowcoder.com/images/20141114/51_1415949515175_1.jpg  )
或者直接访问   http://www.nowcoder.com/pat/2/problem/257

如你所见，蜜蜂的蜂房是正六边形，假设蜜蜂只会从左往右爬，即从1号蜂房能爬到2号和3号；
从6号蜂房能爬到7号和8号……
现给出两个蜂房的编号a和b，要求计算蜂房a的蜜蜂爬到蜂房b有几条不同路线。
每组测试用例包含两个正整数a和b，(0 < a < b < 2^31)          //int 
每组用例的结果单独输出一行。输出数据结果范围是 [0, 2^63)。  //long long
*/


int main(){

	
	/*由于结果的范围较大，不能一一列举，故此
	在一定可靠范围内提供一些常用结果，范围以外的适时进行计算*/
long long b[100];
b[0]=0;b[1]=1;b[2]=2;
b[3]=3;b[4]=5;
for(int i=5;i<100;i++){
	b[i]=b[i-1]+b[i-2];
}	
	//---------------------------------
	int n;
	scanf("%d",&n) ;
int*a=(int *)malloc(sizeof(int)*n);
int from,to;
for(int i=0;i<n;i++){
	scanf("%d%d",&from,&to);
	a[i]=to-from;
}

//printf("80-%lld,81-%lld,82-%lld\n",b[80],b[81],b[82]);
for(int i=0;i<n;i++){
	if(a[i]<100)printf("%lld\n",b[a[i]]);
	else {
		long long c=b[79],d=b[78],e;
		for(int j=100;j<=a[i];j++){
			e=d+c;
			d=c;c=e;
		}
		printf("%lld\n",e);
	}	
}



return 0;
}

