#include<stdio.h>
#include<stdlib.h>
#define N
int main() {
	printf("Input n:\n");
	int n;
	scanf("%d",&n);

	int result[100]={0};int cnt=0;

	for(int j=2; j<=n; j++) {
	int	s=0,y=0;
		for(int i=1; i<j; i++) {
			if(j%i==0)
				s+=i;
		}
		for(int i=1; i<s; i++) {
			if(s%i==0)y+=i;
		}
		if(y==j&&y!=s){int flag=1;
			for(int i=0;i<cnt;i++){
				if(y==result[i]){flag=0;break;}
			}
			if(flag){printf( "(%d,%d)\n",j,s);
			result[cnt++]=s;result[cnt++]=y;}
		}
	}
	return 0;
}

