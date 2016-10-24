#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main()
{
	int  m;
	do {
		printf("Input m(m>0):");
		scanf("%d", &m);
	} while (m < 0);
	printf("%d! = %lu\n", m, Fact(m));
	return 0;
}

//函数功能：用迭代法计算无符号整型变量n的阶乘并返回

unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
	unsigned long result = 1;
	for (i=2; i<=n; i++)
	{
		result *= i;
	}
	return result;
}
