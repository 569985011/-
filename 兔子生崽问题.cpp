#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int parents(int);
int main() {
	int a=0;
	int b=0;
	for(int i=1; i<=12; i++) {
		a=parents(i+1);
		printf("%4d",a);
	}
	b=parents(12+1);
	printf("\nTotal=%d\n",b);
	return 0;
}
int parents(int a) {
	if(a==1||a==2)return 1;
	else return parents(a-1)+parents(a-2);

}

