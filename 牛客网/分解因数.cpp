
#include <stdio.h>

int main() {
	int n;
	int a[10000]= {0};
//	printf("1");
	for(int f=6; f<10000; f++) {
		if(a[f]==0) {
			int m=f;
			for(int i=2; i<m&&!a[m]; ++i) {
				if(m%i==0) {
					a[m]=m/i;
					m/=i;
					--i;
				}
			}
		}
	}

	while((scanf("%d",&n))!=EOF) {
		printf("%d = ",n);
		while(n) {
			if(n>9999) {
				int m=n;
				for(int i=2; i<m&&m>9999; ++i) {
					if(n%i==0) {
						n/=i;
						printf("%d * ",i);
						break;
					}
				}
			} else
				while(a[n]) {
					printf("%d * ",n/a[n]);
					n=a[n];
				}
			printf("%d\n",n);
		}

	}
return 0;
}



