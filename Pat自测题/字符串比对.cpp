#include<stdio.h>

#define N 10000
int found(char*str1,char*);
int main() {
	char str1[N];
	char str2[N];
	gets(str1);

	gets(str2);
	int cnt;
	cnt=found(str1,str2);
	if(cnt==0)printf("-1");
	return 0;
}
int found(char*str1,char*str2) {
	char*f=str1,*p=str2;
	int cnt=0;

	for(int i=0;str2[i]; i++) {
		if(str1[0]==str2[i]) {

			p=&str2[i];
			f=str1;
			int flat=0;
			while(*f) {
				if(*p++!=*f++)flat=-1;

			}
			if(!flat) {
				cnt++;
				printf("%d ",i);

			}
		}

	}

	return cnt;
}
