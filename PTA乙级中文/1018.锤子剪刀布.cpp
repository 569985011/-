#include<stdio.h>

#define N
int main() {
	int n;
	scanf("%d",&n);
	int A[3]= {0},B[3]= {0};
	char a,b;
	int ca=0,cb=0,ja=0,jb=0,ba=0,bb=0;
	for(int i=0; i<n; i++) {
		scanf(" %c %c",&a,&b);
		if(a=='C'&&b=='J') {
			A[0]++;
			B[2]++;
			ca++;
		} else	if(b=='C'&&a=='J') {
			B[0]++;
			A[2]++;
			cb++;
		} else	if(a=='J'&&b=='B') {
			A[0]++;
			B[2]++;
			ja++;
		} else	if(b=='J'&&a=='B') {
			B[0]++;
			A[2]++;
			jb++;
		} else	if(a=='B'&&b=='C') {
			A[0]++;
			B[2]++;
			ba++;
		} else	if(b=='B'&&a=='C') {
			B[0]++;
			A[2]++;
			bb++;
		} else if(a==b) {
			A[1]++;
			B[1]++;
		}

	}
	for(int i=0; i<3; i++) {
		if(i)printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");

	for(int i=0; i<3; i++) {
		if(i)printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");

	if(ba>=ca) {
		if(ba>=ja)printf("B");else
		printf("J");
	} else if(ca>=ja)
		printf("C");
	else printf("J");
printf(" ");

	if(bb>=cb) {
		if(bb>=jb)printf("B");else
		printf("J");
	} else if(cb>=jb)
		printf("C");
	else printf("J");
	return 0;
}

