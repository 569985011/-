#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 149
int main() {
	int a[N]= {0};
	int cnt=0;

 	for(int i=0,cnt=0; cnt<21; i++) {
		if(i%5==0) {
			a[i]=1;//printf("第%d次i=%d\t",cnt,i);
		cnt++;
		}
	}
	for(int i=0,cnt=0; cnt<21; i++) {
		if(i%6==0) {
			a[i]=1;//printf("第%d次i=%d\t",cnt,i);
		cnt++;
		}
	}
	for(int i=0,cnt=0; cnt<21; i++) {
		if(i%7==0) {
			a[i]=1;//printf("第%d次i=%d\t",cnt,i);
		cnt++;
		}
	}

	int listen=0;
	for(int i=0; i<N; i++)if(a[i]==1)listen++;
	printf("n=%d",listen);
	return 0;
}

