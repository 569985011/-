#include<stdio.h>
#include<stdlib.h>
#define N
typedef struct {
	char a[19];
	char check;
} IDCard;
int main() {
	int n;int cnt=0;
	scanf("%d",&n);
	IDCard*a=(IDCard*)calloc(n,sizeof(IDCard));
	for(int i=0; i<n; i++) {
		scanf("%s",&a[i].a);
	//	printf("%s\n",a[i].a);
	}
	for(int i=0; i<n; i++) {
		int sum=0;int flag=0;
		for(int j=0; j<17; j++) {
			if(a[i].a[j]<'0'||a[i].a[j]>'9') {
				flag=1;break;
			}
		}
		if(!flag) {
			for(int j=0; j<17; j++) {
				switch(j) {
					case 0:
						sum=(a[i].a[j]-'0')*7;
						break;
					case 1:
						sum+=(a[i].a[j]-'0')*9;
						break;
					case 2:
						sum+=(a[i].a[j]-'0')*10;
						break;
					case 3:
						sum+=(a[i].a[j]-'0')*5;
						break;
					case 4:
						sum+=(a[i].a[j]-'0')*8;
						break;
					case 5:
						sum+=(a[i].a[j]-'0')*4;
						break;
					case 6:
						sum+=(a[i].a[j]-'0')*2;
						break;
					case 7:
						sum+=(a[i].a[j]-'0');
						break;
					case 8:
						sum+=(a[i].a[j]-'0')*6;
						break;
					case 9:
						sum+=(a[i].a[j]-'0')*3;
						break;
					case 10:
						sum+=(a[i].a[j]-'0')*7;
						break;
					case 11:
						sum+=(a[i].a[j]-'0')*9;
						break;
					case 12:
						sum+=(a[i].a[j]-'0')*10;
						break;
					case 13:
						sum+=(a[i].a[j]-'0')*5;
						break;
					case 14:
						sum+=(a[i].a[j]-'0')*8;
						break;
					case 15:
						sum+=(a[i].a[j]-'0')*4;
						break;
					case 16:
						sum+=(a[i].a[j]-'0')*2;
						break;
				}
			}
			switch(sum%11) {
				case 0:
					a[i].check='1';
					break;
				case 1:
					a[i].check='0';
					break;
				case 2:
					a[i].check='X';
					break;
				case 3:
					a[i].check='9';
					break;
				case 4:
					a[i].check='8';
					break;
				case 5:
					a[i].check='7';
					break;
				case 6:
					a[i].check='6';
					break;
				case 7:
					a[i].check='5';
					break;
				case 8:
					a[i].check='4';
					break;
				case 9:
					a[i].check='3';
					break;
				case 10:
					a[i].check='2';
					break;

			}
			if(a[i].check!=a[i].a[17])flag=1;
		}
		if(flag){printf("%s\n",a[i].a);cnt++;}
	}
	if(!cnt)printf("All passed");


return 0;
}

