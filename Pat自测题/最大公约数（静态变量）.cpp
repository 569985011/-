#include<stdio.h>

#define N
int CommonFactors(int a, int b);
int main() {
	printf("Input a and b:\n");

	int a,b;
	int cnt=0;
	scanf("%d,%d",&a,&b);
	int flag=CommonFactors(a,b);
	while(flag!=-1) {
		cnt++;
		printf("Common factor %d is %d\n",cnt,flag);
	flag=CommonFactors(a,b);
	}
	return 0;
}
int CommonFactors(int a, int b) {
	static int max=a;
	static int result=0;
//	printf("---result%d----max-%d\n",result,max);
	for(int i=max; i>0; i--) {
		if(a%i==0&&b%i==0&&a>0&&b>0) {
			if(result==0) {
				max=i;result=i;
				return result;
			} else {
				if(i<max) {
					max=i;result=i;
					return result;
				}
			}
		}
		
	}
	return -1;
}
