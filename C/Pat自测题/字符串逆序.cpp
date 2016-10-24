#include<stdio.h>

#include<string.h>
#define N 81
void Inverse(char str[]);
int main() {
	char a[N];
 printf("Input a string:\n");
	gets(a);
	Inverse(a);
	return 0;
}
void Inverse(char str[]) {
	int len;
	len=strlen(str)-1;
	char temp;
	for(int i=0,j=len;i<j; i++,j--) {
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
printf("Inversed results:\n");

puts(str);
}
