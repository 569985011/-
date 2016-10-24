#include<stdio.h>
#define N 15
int ISBN(int ,int,int);
int main() {
	char a[N];
	gets(a);
	int lan=0,press=0,number=0;
	int check;
	lan=a[0]-'0';
	for(int i=2; i<5; i++)
		press=press*10+(a[i]-'0');
	for(int i=6; i<11; i++)
		number=number*10+(a[i]-'0');
	check=a[12]-'0';
	if(check==ISBN(lan,press,number))printf("Right");
	else printf("%d-%d-%d-%d",lan,press,number,
		            ISBN(lan,press,number));
	return 0;
}
int ISBN(int lan,int press,int number) {

	int sum=0;
	sum=lan*1;
	int a=0;
	int b;
	for(int i=2,b=100; i<5; i++) {
		a=press/b;
		press-=a*b;
		b/=10;
		sum+=i*a;
	}
	for(int i=6,b=10000; i<11; i++) {
		a=number/b;
		number-=a*b;
		b/=10;
		sum+=(i-1)*a;
	}
	return sum%11;
	return 0;
}
