#include<stdio.h>
#include<string.h>//反正你给的代码里没有引用头文件，
#define N 80
int main()
{
	char str[N];
	int i,len;
	char temp;
	printf("Input a string:\n");
	gets(str);
	len=strlen(str)-1;//修改此处即可
	
	for(i=0;i<(len/2);i++)
	{   //printf("%c-%c ",str[i],str[len-i]);
	/*     在这里插入输出语句检测出问题出在第一次交换，你就把“\0”交给了开头；
	这就导致后面输出str输到第一个就停止了        */
		temp=str[i];
		str[i]=str[len-i];
		str[len-i]=temp;
		
	}
	printf("Inversed results:\n");
	puts(str);
	return 0;
}
