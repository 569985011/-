#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int main() {
	char a[N],b[N];
	char c[N];
	gets(a);
	gets(b);
	for(int i=0; i<strlen(a); i++) {
		if(a[i]>='a'&&a[i]<='z')a[i]-=32;
	}
	for(int i=0; i<strlen(b); i++) {
		if(b[i]>='a'&&b[i]<='z')b[i]-=32;
	}
	/*´óÐ¡Ð´
	int Isbig=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='A'&&a[i]<='Z'){IsBig=1;break;}
	}
	for(int i=0;i<strlen(b),IsBig;i++){
		if(b[i]>='A'&&b[i]<='Z'){IsBig=2;break;}
	}
	for(int i=0;i<strlen(a),IsBig==0;i++){
		if(b[i]>='a'&&b[i]<='Z'){IsBig=1;break;}
	}
	for(int i=0;i<)
	*/
	int d=0;
	for(int i=0; i<strlen(a); i++) {
		int flag=0;
		for(int j=0; j<=i; j++) {
			if(b[j]==a[i]) {
				flag=1;
				break;
			}
		}
		if(!flag) {
			for(int f=0; f<d; f++) {
				if(c[f]==a[i]) {
					flag=1;
					break;
				}
			}
		}
		if(!flag) {
			c[d++]=a[i];
			printf("%c",a[i]);

		}

	}
	return 0;
}

