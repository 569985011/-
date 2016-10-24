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
	int cnt=0,n,m;
	scanf("%d%d",&m,&n);
	for(int i=0; cnt<n; i++) {
		if(ispromise(i)) {
			cnt++;
			if(cnt>m&&(cnt-m)%10==0)printf("\n");
			else if(cnt>m)printf(" ");
			if(cnt>=m)printf("%d",i);
		}
	}

	return 0;
}

