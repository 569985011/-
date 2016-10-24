#include<stdio.h>
#include<math.h>
#define N
int ispromise(int a) {
	if(a<2)return 0;
	if(a==2||a==3)return 1;
	for(int i=2; i<=sqrt(a); i++) {
		if(a%i==0)return 0;
	}

	return 1;
}
int main() {
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=2; i<=n-2; i++) {
		if(ispromise(i)&&ispromise(i+2)) {
			cnt++;
		//	printf("%d-%d ",i,i+2);
		}
	}
	printf("%d",cnt);
	return 0;
}

