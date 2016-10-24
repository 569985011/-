#include<stdio.h>
#include<string.h>
#define N
void ScanOrder(int*);
void Washpuk(const int *a,char(*p)[4]) ;
int main() {

	char puk[55][4]= {"0","S1","S2","S3","S4","S5","S6","S7",
	                  "S8","S9","S10","S11","S12","S13",
	                  "H1","H2","H3","H4","H5","H6","H7",
	                  "H8","H9","H10","H11","H12","H13",
	                  "C1","C2","C3","C4","C5","C6","C7",
	                  "C8","C9","C10","C11","C12","C13",
	                  "D1","D2","D3","D4","D5","D6","D7",
	                  "D8","D9","D10","D11","D12","D13",
	                  "J1","J2"
	                 };
//for(int i=0;i<54;i++)printf("%s ",puk[i]);
	int time;
	scanf("%d",&time);
	int order[55];
	ScanOrder(order);
//	for(int i=1;i<55;i++)printf("%d ",order[i]);
//	printf("\n-----------\n");
	for(int i=0; i<time; i++)
		Washpuk(order,puk);
	for(int i=1; i<55; i++) {
		if(i>1)printf(" ");
		printf("%s",puk[i]);
	}
	return 0;
}
void ScanOrder(int*a) {
	for(int i=1; i<55; i++) {
		scanf("%d",&a[i]);
	}
}
void Washpuk(const int *a,char(*p)[4]) {
	char dui[55][4]= {0};
	for(int i=1; i<55; i++) {
		strcpy(dui[a[i]],p[i]);
	}
	for(int i=1; i<55; i++) {
		strcpy(p[i],dui[i]);
	}
}
