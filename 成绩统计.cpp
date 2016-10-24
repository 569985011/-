#include<stdio.h>

#define N
typedef struct {
	char name[10];
	int average;
	int score[4];
} STU;
int main() {
	STU a[4]= {{"wanglei",0,{78,90,87,92}},{"lihong",0,{88,91,89,78}},{"zhangli",0,{84,76,83,75}},{"liuming",0,{88,90,71,83}}};
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			a[i].average+=a[i].score[j];
		}

	//	printf("%d-%.2f",i,a[i].average);
	}//printf("\n------------\n");
	for(int i=0;i<4;i++){
		printf("%s,",a[i].name);
		if(a[i].average%4==0)printf("%d\n",a[i].average/4);
		else printf("%.2f\n",a[i].average/4.0);
	}
	printf("AVERAGE:");
	int av=0;
	for(int i=0;i<4;i++){
		av=0;
		for(int j=0;j<4;j++){
			av+=a[j].score[i];
		};
		if(i)printf(",");
		if(av%4==0){
			printf("%d",av/4);
		}else printf("%.2f",av/4.0);
	}printf("\n");
	return 0;
}

