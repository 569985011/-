#include <stdio.h>
#include<string.h>
#define   MAX_LEN  10        	/* 字符串最大长度 */
#define   STU_NUM 30      /* 最多的学生人数 */
void  SwapFloat(float *x, float *y) {
	float u;
	u=*x;
	*x=*y;
	*y=u;
}
void  SwapLong(long *x, long *y) {
	long u;
	u=*x;
	*x=*y;
	*y=u;
}
void  SwapChar(char x[], char y[]) {
	char u[MAX_LEN];
	strcpy(u,x);
	strcpy(x,y);
	strcpy(y,u);
}
int   Ascending(float a, float b) {
	return a>b;
}
int   Descending(float a, float b) {
	return a<b;
}
int   Menu(void) {
	printf("Management for Students' scores\n\
1.Input record\n\
2.Caculate total and average score of course\n\
3.Sort in descending order by score\n\
4.Sort in ascending order by score\n\
5.Sort in ascending order by number\n\
6.Sort in dictionary order by name\n\
7.Search by number\n\
8.Search by name\n\
9.Statistic analysis\n\
10.List record\n\
0.Exit\n\
Please Input your choice:\n");
	int n;
	scanf("%d",&n);
	return n;
}
void  ReadScore(long num[], char name[][MAX_LEN], float score[], int n) {
	printf("Input student's ID, name and score:\n");
	for(int i=0; i<n; i++) {
		scanf("%ld%s%f",&num[i],name[i],&score[i]);
	}
}
void  AverSumofScore(float score[], int n) {
	float sum=0;
	for(int i=0; i<n; i++)sum+=score[i];
	printf("sum=%.0f,aver=%.2f\n",sum,sum/n);
}
void  SortbyScore(long num[], char name[][MAX_LEN], float score[], int n,
                  int (*compare)(float a, float b)) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if((*compare)(score[j],score[i])) {
				SwapFloat(&score[i],&score[j]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);

			}
		}
	}

}


void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(num[j]<num[i]) {
				SwapFloat(&score[i],&score[j]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);

			}
		}
	}
}
void  SortbyName(long num[], char name[][MAX_LEN], float score[], int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(strcmp(name[i],name[j])>0) {
				SwapFloat(&score[i],&score[j]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);
			}
		}
	}
}
void  SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n) {
	long key;
	int flag=0;
	printf("Input the number you want to search:\n");
	while(getchar()!='\n');
	scanf("%ld",&key);
	for(int i=0; i<n; i++) {
		if(num[i]==key) {
			flag=1;
			printf("%ld\t%s\t%.0f\n",num[i],name[i],score[i]);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
}
void  SearchbyName(long num[], char name[][MAX_LEN], float score[], int n) {
	char key[MAX_LEN];
	printf("Input the name you want to search:\n");
	while(getchar()!='\n');
	scanf("%s",key);
	while(getchar()!='\n');
	int flag=0;
	for(int i=0; i<n; i++) {
		if(strcmp(name[i],key)==0) {
			flag=1;
			printf("%ld\t%s\t%.0f\n",num[i],name[i],score[i]);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
}
void  StatisticAnalysis(float score[], int n){
	int array[11]= {0};
	for(int i=0; i<n; i++) {
		if(score[i]<60)array[5]++;
		else if(score[i]<70)array[6]++;
		else if(score[i]<80)array[7]++;
		else if(score[i]<90)array[8]++;
		else if(score[i]<100)array[9]++;
		else if(score[i]==100)array[10]++;
	}
	printf("<60\t%d\t%.2f%%\n",array[5],array[5]*100.0/n);
	printf("%d-%d\t%d\t%.2f%%\n",60,69,array[6],array[6]*100.0/n);
	printf("%d-%d\t%d\t%.2f%%\n",70,79,array[7],array[7]*100.0/n);
	printf("%d-%d\t%d\t%.2f%%\n",80,89,array[8],array[8]*100.0/n);
	printf("%d-%d\t%d\t%.2f%%\n",90,99,array[9],array[9]*100.0/n);
	printf("%d\t%d\t%.2f%%\n",100,array[10],array[10]*100.0/n);
}
void  PrintScore(long num[], char name[][MAX_LEN], float score[], int n) {
	for(int i=0; i<n; i++) {
		printf("%ld\t%s\t%.0f\n",num[i],name[i],score[i]);
	}
}
int main() {
	int choice;
	long num[STU_NUM];
	char name[STU_NUM][MAX_LEN];
	float score[STU_NUM];
	int n;
	printf("Input student number(n<30):\n");
	scanf("%d",&n);
u1:
	choice=Menu();
	switch(choice) {
		case 1:
			ReadScore(num,name,score,n);
			goto u1;
			break;
		case 2:
			AverSumofScore(score,n);
			goto u1;
			break;
		case 3:
			SortbyScore(num,name,score,n,Ascending);
			printf("Sort in descending order by score:\n");
			PrintScore(num,name,score,n);
			goto u1;
			break;
		case 4:
			SortbyScore(num,name,score,n,Descending);
			printf("Sort in ascending order by score:\n");
			PrintScore(num,name,score,n);
			goto u1;
			break;
		case 5:
			AsSortbyNum(num,name,score,n);
			printf("Sort in ascending order by number:\n");
			PrintScore(num,name,score,n);
			goto u1;
			break;
		case 6:
			SortbyName(num,name,score,n);
			printf("Sort in dictionary order by name:\n");
			PrintScore(num,name,score,n);
			goto u1;
			break;
		case 7:
			SearchbyNum(num,name,score,n);
			goto u1;
			break;
		case 8:
			SearchbyName(num,name,score,n);
			goto u1;
			break;
		case 9:
			StatisticAnalysis(score,n);
			goto u1;
			break;
			case 10:
				PrintScore(num,name,score,n);
				goto u1;
				break;
		case 0:
			printf("End of program!\n");
			break;
		default:
			printf("Input error!\n");
			goto u1;
			break;
	}

	return 0;
}
