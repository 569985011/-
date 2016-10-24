#include<stdio.h>

int main()
{
	int a;int b;int t;
	scanf("%d %d",&a,&b);
	t=a;a=b;b=t; 
	printf("%d %d",a,b);
    return 0;
}
