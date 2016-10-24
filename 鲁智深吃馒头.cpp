#include<stdio.h>
#define N 101
int main() {
	int a[N];
	int mantou=99;int u;
	for( u=1; u<N; u++)a[u]=1;
//	printf("人数：%d",u);
	int cnt=0;
	while(mantou) {
		
		for(int i=1; i<N; i++) {
			if(a[i]!=0) {
				cnt++;//printf("%d",cnt);
				if(cnt==5) {
					a[i]=0;
	 				mantou--;
					
				//	printf("馒头剩%d个",mantou);
					cnt=0;
				//	printf("第%d个\t",i);
				//	if(mantou==0)break;
				}
			}

		}

	}
	for(int u=1;u<N;u++)if(a[u]==1)printf("%d",u);
	return 0;
}

