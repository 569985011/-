#include<stdio.h>
int mid(int a, int b, int c);
int main() {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int result;
	result=mid(a,b,c);
	printf("The result is %d\n",result);
	return 0;
}
int mid(int a,int b,int c) {
	if(a>=b) {
		if(b>=c)return b;
		else if(c>=a)
			return a;
		else return c;
	} else if(a<=c) {
		if(c<=b)return c;
		else return b;
	} else return a;
}

