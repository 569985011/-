#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   MAX_LEN  10                	    /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
typedef struct student
{
    long num;						/* 每个学生的学号 */
    char name[MAX_LEN];            	/* 每个学生的姓名 */
    float score[COURSE_NUM];		/* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                   	     /* 每个学生的总成绩 */
    float aver;               	     /* 每个学生的平均成绩 */
}STU;
int   Menu(void);
void  ReadScore(STU stu[], int n, int m);
void  AverSumofEveryStudent(STU stu[], int n, int m);
void  AverSumofEveryCourse(STU stu[], int n, int m);
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  SwapFloat(float *x, float *y);
void  SwapLong(long *x, long *y);
void  SwapChar(char x[], char y[]);
void  AsSortbyNum(STU stu[], int n, int m);
void  SortbyName(STU stu[], int n, int m);
void  SearchbyNum(STU stu[], int n, int m);
void  SearchbyName(STU stu[], int n, int m);
void  StatisticAnalysis(STU stu[], int n, int m);
void  PrintScore(STU stu[], int n, int m);
int main() {
	int n;//学生人数
	int m;
	printf("Input student number(n<30):\n");
	scanf("%d",&n);
	STU*stu=(STU*)calloc(n,sizeof(STU));
	int choice;
u1:
	choice=Menu();
	switch(choice) {
		case 1:
			printf("Input course number(m<=%d):\n",COURSE_NUM);
			scanf("%d",&m);
			printf("Input student's ID, name and score:\n");
			ReadScore(stu,n,m);
			goto u1;
			break;
		case 2:
			AverSumofEveryCourse(stu,n,m);
			goto u1;
			break;
		case 3:
			AverSumofEveryStudent(stu,n,m);
			goto u1;
			break;
		case 4:
			SortbyScore(stu,n,m,Descending);
			printf("Sort in descending order by score:\n");
			PrintScore(stu,n,m);
			goto u1;
			break;
		case 5:
			SortbyScore(stu,n,m,Ascending);
			printf("Sort in ascending order by score:\n");
			PrintScore(stu,n,m);
			goto u1;
			break;
		case 6:
			AsSortbyNum(stu,n,m);
			printf("Sort in ascending order by number:\n");
			PrintScore(stu,n,m);
			goto u1;
			break;
		case 7:
			SortbyName(stu,n,m);
			printf("Sort in dictionary order by name:\n");
			PrintScore(stu,n,m);
			goto u1;
			break;
		case 8:
			SearchbyNum(stu,n,m);
			goto u1;
			break;
		case 9:
			SearchbyName(stu,n,m);
			goto u1;
			break;
		case 10:
			StatisticAnalysis(stu,n,m);
			goto u1;
			break;
		case 11:
			PrintScore(stu,n,m);
			goto u1;
			break;
		case 0:
			printf("End of program!");
			break;
		default:
			printf("Input error!\n");
			goto u1;
			break;
	}

	return 0;
}
void  PrintScore(STU stu[], int n, int m){
		for(int i=0; i<n; i++) {
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for(int j=0; j<m; j++) {
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}
}
void  StatisticAnalysis(STU stu[], int n, int m){
		for(int j=0; j<m; j++) {
		int array[11]= {0};
		for(int i=0; i<n; i++) {
			if(stu[i].score[j]<60)array[5]++;
			else if(stu[i].score[j]<70)array[6]++;
			else if(stu[i].score[j]<80)array[7]++;
			else if(stu[i].score[j]<90)array[8]++;
			else if(stu[i].score[j]<100)array[9]++;
			else if(stu[i].score[j]==100)array[10]++;
		}
		printf("For course %d:\n",j+1);
		printf("<60\t%d\t%.2f%%\n",array[5],array[5]*100.0/n);
		printf("%d-%d\t%d\t%.2f%%\n",60,69,array[6],array[6]*100.0/n);
		printf("%d-%d\t%d\t%.2f%%\n",70,79,array[7],array[7]*100.0/n);
		printf("%d-%d\t%d\t%.2f%%\n",80,89,array[8],array[8]*100.0/n);
		printf("%d-%d\t%d\t%.2f%%\n",90,99,array[9],array[9]*100.0/n);
		printf("%d\t%d\t%.2f%%\n",100,array[10],array[10]*100.0/n);
	}
}
void  SearchbyName(STU stu[],int n, int m) {
	char key[MAX_LEN];
	printf("Input the name you want to search:\n");
	scanf("%s",key);
	while(getchar()!='\n');
	int flag=0;
	for(int i=0; i<n; i++) {
		if(strcmp(stu[i].name,key)==0) {
			flag=1;
			printf("%ld\t%s\t",stu[i].num,stu[i].name);
			for(int j=0; j<m; j++)printf("%.0f\t",stu[i].score[j]);
			printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
}
void  SearchbyNum(STU stu[], int n, int m){
	long key;
	int flag=0;
	printf("Input the number you want to search:\n");
	scanf("%ld",&key);
	for(int i=0; i<n; i++) {
		if(stu[i].num==key) {
			flag=1;
			printf("%ld\t%s\t",stu[i].num,stu[i].name);
			for(int j=0; j<m; j++)printf("%.0f\t",stu[i].score[j]);
			printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
}
void  SortbyName(STU stu[], int n, int m){
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(strcmp(stu[i].name,stu[j].name)>0) {
			for(int f=0;f<m; f++)SwapFloat(&stu[i].score[f],&stu[j].score[f]);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapChar(stu[i].name,stu[j].name);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[j].aver);
			}
		}
	}
}
void  AsSortbyNum(STU stu[], int n, int m){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(stu[i].num>stu[j].num){
				for(int f=0;f<m; f++)SwapFloat(&stu[i].score[f],&stu[j].score[f]);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapChar(stu[i].name,stu[j].name);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[j].aver);
			}
		}
	}
}
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b)){
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if((*compare)(stu[i].sum,stu[j].sum)) {
			for(int f=0;f<m; f++)SwapFloat(&stu[i].score[f],&stu[j].score[f]);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapChar(stu[i].name,stu[j].name);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[j].aver);
			}
		}
	}
}

void  AverSumofEveryStudent(STU stu[], int n, int m) {
	for(int i=0; i<n; i++) {
		float sum=0;
		for(int j=0; j<m; j++) {
			sum+=stu[i].score[j];
		}
		stu[i].sum=sum;
		stu[i].aver=sum/m;
		printf("student %d: sum=%.0f,aver=%.0f\n",i+1,stu[i].sum,stu[i].aver);
	}
}
void  AverSumofEveryCourse(STU stu[], int n, int m) {
	for(int i=0; i<m; i++) {
		float sum=0;
		for(int j=0; j<n; j++) {
			sum+=stu[j].score[i];
		}
		printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum,sum/n);
	}
}
void  ReadScore(STU stu[], int n, int m) {
	for(int i=0; i<n; i++) {

		scanf("%ld",&stu[i].num);
		scanf("%s",stu[i].name);
		for(int j=0; j<m; j++)
			scanf("%f",&stu[i].score[j]);

	}
}
int Menu(void) {
	printf("Management for Students' scores\n\
1.Input record\n\
2.Caculate total and average score of every course\n\
3.Caculate total and average score of every student\n\
4.Sort in descending order by score\n\
5.Sort in ascending order by score\n\
6.Sort in ascending order by number\n\
7.Sort in dictionary order by name\n\
8.Search by number\n\
9.Search by name\n\
10.Statistic analysis\n\
11.List record\n\
0.Exit\n\
Please Input your choice:\n");
	int n;
	scanf("%d",&n);
	return n;
}
int Ascending(float a,float b) {
	return a>b;
}
int   Descending(float a, float b) {
	return a<b;
}
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
