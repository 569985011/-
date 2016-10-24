#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(x,y) x>y?x:y
/*error :2 9 10 Yes->No
还是要进行进位计算。。。。*/
void char2int (char*a,int *b) {

	for(int i=0; i<strlen(a); i++) {
		b[i]=a[i]-'0';
	}
	for(int i=0; i<strlen(a)/2; i++) {
		int swap=b[i];
		b[i]=b[strlen(a)-1-i];
		b[strlen(a)-1-i]=swap;
	}
//	printf("tt:%s->",a);
//	for(int i=0; i<strlen(a); i++)printf("%d ",b[i]);
//	printf("\n");
}
int YoN(char*ca,char*cb,char*cc) {
	if(0==strcmp(ca,"0")||0==strcmp(cb,"0")||0==strcmp(cc,"0"))
		return 0;
	int a[101],b[101],c[101],sum[102]= {0};
	char2int(ca,a);
	char2int(cb,b);
	char2int(cc,c);

	for(int i=0; i<strlen(ca); i++) {
		sum[i]=a[i];
	}
	for(int i=0; i<strlen(cb); i++) {
		sum[i]+=b[i];
	}
	for(int i=0; i<strlen(cc); i++) {
		sum[i]+=c[i];
	}
	int lenth=max(max(strlen(ca),strlen(cb)),strlen(cc));
//	printf("sum=");
//	for(int i=0; i<lenth; i++)printf("%d ",sum[i]);
//	printf("\n---------\n");
	if(strlen(ca)==lenth) {
		for(int i=lenth-1; i>=0; i--) {
			if(a[i]>sum[i]/2.0) {
//				printf("test:1\n");
				return 0;
			} else if(a[i]<sum[i]/2.0) {
//				printf("4/2.0");
				if(strlen(cb)==lenth||strlen(cc)==lenth)break;
				else return 1;
			} else {
				if(i==0) {
					return 0;
				}
			}
		}
	}
	if(strlen(cb)==lenth) {
		for(int i=lenth-1; i>=0; i--) {
			if(b[i]>sum[i]/2.0) {
//				printf("test:2\n");
				return 0;

			} else if(b[i]<sum[i]/2.0) {
//				printf("43/2.0");
				if(strlen(cc)==lenth)break;
				else return 1;
			} else {
				if(i==0) {
					return 0;
				}
			}
		}
	}
	if(strlen(cc)==lenth) {

		for(int i=lenth-1; i>=0; i--) {
			if(c[i]>sum[i]/2.0) {
//				printf("test:3\n");
				return 0;
			} else if(c[i]<sum[i]/2.0) {
//				printf("41/2.0");
				return 1;

			} else {
				if(i==0) return 0;

			}
		}
	}
//	printf("jj");
	return 0;
}

int main() {

	char ca[101],cb[101],cc[101];
	while((scanf("%s%s%s",ca,cb,cc))!=EOF) {

		if(YoN(ca,cb,cc))printf("Yes\n");
		else printf("No\n");
	};


	return 0;
}

