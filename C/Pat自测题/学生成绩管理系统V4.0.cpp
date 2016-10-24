#include<stdio.h>
#include<string.h>

#define   MAX_LEN  10                		/* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
int   Menu(void);
void  ReadScore(long num[], char name[][MAX_LEN],
                float score[][COURSE_NUM], int n, int m);
void AverSumofEveryStudent(float score[][COURSE_NUM], int n, int m,
                           float  sum[STU_NUM], float aver[STU_NUM]);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);
void  SortbyScore(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m, int (*compare)(float a, float b));
int Ascending(float a,float b){
	return a>b;
}
int   Descending(float a, float b){
return a<b;
}
void  SwapFloat(float *x, float *y){
	float u;u=*x;*x=*y;*y=u;
}
void  SwapLong(long *x, long *y){
	long u;u=*x;*x=*y;*y=u;
}
void  SwapChar(char x[], char y[]){
	char u[MAX_LEN];
	strcpy(u,x);
	strcpy(x,y);
	strcpy(y,u);
}
void  AsSortbyNum(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m);
void  SortbyName(long num[], char name[][MAX_LEN],
                 float score[][COURSE_NUM], float  sum[], float aver[],
                 int n, int m);
void  SearchbyNum(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m);
void  SearchbyName(long num[], char name[][MAX_LEN],
                   float score[][COURSE_NUM], float  sum[], float aver[],
                   int n, int m);
void  StatisticAnalysis(float score[][COURSE_NUM], int n, int m);
void  PrintScore(long num[], char name[][MAX_LEN],
                 float score[][COURSE_NUM], float  sum[], float aver[],int n, int m) ;
int main() {
	int choice;
	long num[STU_NUM];
	char name[STU_NUM][MAX_LEN];
	float score[STU_NUM][COURSE_NUM];
	float sum[STU_NUM],aver[STU_NUM];
	int n,m;
	printf("Input student number(n<30):\n");
	scanf("%d",&n);
u1:
	choice=Menu();
	switch(choice) {
		case 1:
			printf("Input course number(m<=6):\n");
			int m;
			scanf("%d",&m);
			printf("Input student's ID, name and score:\n");
			ReadScore(num,name,score,n,m);
			goto u1;
			break;
		case 2:
			AverSumofEveryCourse(score,n,m);
			goto u1;
			break;
		case 3:
			AverSumofEveryStudent(score,n,m,sum,aver);
			goto u1;
			break;
		case 4:
			SortbyScore(num,name,score,sum,aver,n,m,Descending);
			printf("Sort in descending order by score:\n");
			PrintScore(num,name,score,sum,aver,n,m);
			goto u1;
			break;
		case 5:
			SortbyScore(num,name,score,sum,aver,n,m,Ascending);
			printf("Sort in ascending order by score:\n");
			PrintScore(num,name,score,sum,aver,n,m);
			goto u1;
			break;
		case 6:
			AsSortbyNum(num,name,score,sum,aver,n,m);
			printf("Sort in ascending order by number:\n");
			PrintScore(num,name,score,sum,aver,n,m);
			goto u1;
			break;
			case 7:
				SortbyName(num,name,score,sum,aver,n,m);
				printf("Sort in dictionary order by name:\n");
				PrintScore(num,name,score,sum,aver,n,m);
				goto u1;break;
		case 8:
			SearchbyNum(num,name,score,sum,aver,n,m);
			
			goto u1;
			break;
		case 9:
			SearchbyName(num,name,score,sum,aver,n,m);
			goto u1;
			break;
		case 10:
			StatisticAnalysis(score,n,m);
			goto u1;
			break;
		case 11:
			PrintScore(num,name,score,sum,aver,n,m);
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
void  PrintScore(long num[], char name[][MAX_LEN],
                 float score[][COURSE_NUM], float  sum[], float aver[],int n, int m){
    for(int i=0;i<n;i++){
    	printf("%ld\t%s\t",num[i],name[i]);
    	for(int j=0;j<m;j++){
    		printf("%.0f\t",score[i][j]);
		}
		printf("%.0f\t%.0f\n",sum[i],aver[i]);
	}
				 }
void  StatisticAnalysis(float score[][COURSE_NUM], int n, int m){
	for(int j=0;j<m;j++){
		int array[11]= {0};
	for(int i=0; i<n; i++) {
		if(score[i][j]<60)array[5]++;
		else if(score[i][j]<70)array[6]++;
		else if(score[i][j]<80)array[7]++;
		else if(score[i][j]<90)array[8]++;
		else if(score[i][j]<100)array[9]++;
		else if(score[i][j]==100)array[10]++;
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

void  SearchbyName(long num[], char name[][MAX_LEN],
                   float score[][COURSE_NUM], float  sum[], float aver[],
                   int n, int m){
                   	char key[MAX_LEN];
	printf("Input the name you want to search:\n");
	while(getchar()!='\n');
	scanf("%s",key);
	while(getchar()!='\n');
	int flag=0;
	for(int i=0; i<n; i++) {
		if(strcmp(name[i],key)==0) {
			flag=1;
			printf("%ld\t%s\t",num[i],name[i]);
			for(int j=0;j<m;j++)printf("%.0f\t",score[i][j]);
			printf("%.0f\t%.0f\n",sum[i],aver[i]);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
				   }
void  SearchbyNum(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m){
                  		long key;
	int flag=0;
	printf("Input the number you want to search:\n");
	while(getchar()!='\n');
	scanf("%ld",&key);
	for(int i=0; i<n; i++) {
		if(num[i]==key) {
			flag=1;
			printf("%ld\t%s\t",num[i],name[i]);
			for(int j=0;j<m;j++)printf("%.0f\t",score[i][j]);
			printf("%.0f\t%.0f\n",sum[i],aver[i]);
			break;
		}
	}
	if(!flag)printf("Not found!\n");
				  }
void  SortbyName(long num[], char name[][MAX_LEN],
                 float score[][COURSE_NUM], float  sum[], float aver[],
                 int n, int m){
                 	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(strcmp(name[i],name[j])>0) {
				for(int f=0;f<m;f++)SwapFloat(&score[i][f],&score[j][f]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);
				SwapFloat(&sum[i],&sum[j]);
				SwapFloat(&aver[i],&aver[j]);
			}
		}
	}
}
void  AsSortbyNum(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m){
             for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(num[j]<num[i]) {
				for(int f=0;f<m;f++)SwapFloat(&score[i][f],&score[j][f]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);
				SwapFloat(&sum[i],&sum[j]);
				SwapFloat(&aver[i],&aver[j]);
			}
		}
	}
				  }
void  SortbyScore(long num[], char name[][MAX_LEN],
                  float score[][COURSE_NUM], float  sum[], float aver[],
                  int n, int m, int (*compare)(float a, float b)){
                  	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if((*compare)(sum[i],sum[j])) {
				for(int f=0;f<m;f++)SwapFloat(&score[i][f],&score[j][f]);
				SwapLong(&num[i],&num[j]);
				SwapChar(name[i],name[j]);
				SwapFloat(&sum[i],&sum[j]);
				SwapFloat(&aver[i],&aver[j]);
			}
		}
	}
}
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m){
	for(int i=0;i<m;i++){
		float sum=0;
		for(int j=0;j<n;j++){
			sum+=score[j][i];
		}
		printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum,sum/n);
	}
}
void AverSumofEveryStudent(float score[][COURSE_NUM], int n, int m,
                           float  sum[STU_NUM], float aver[STU_NUM]){
for(int i=0;i<n;i++){
	float f_sum=0;
	for(int j=0;j<m;j++){
		f_sum+=score[i][j];
	}sum[i]=f_sum;
	aver[i]=f_sum/m;
	printf("student %d:sum=%.0f,aver=%.0f\n",i+1,sum[i],aver[i]);
}
  }
void  ReadScore(long num[], char name[][MAX_LEN],
                float score[][COURSE_NUM], int n, int m) {
for(int i=0; i<n; i++) {

		scanf("%ld%s",&num[i],&name[i]);
		for(int j=0;j<m;j++){
			scanf("%f",&score[i][j]);
		}
	}
}
int Menu() {
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
