#define   MAX_LEN  10                		/* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#include<stdio.h>
#include<stdlib.h>
int   Menu(void);
void  ReadScore(long num[],float score[], int n);
void AverSumofEveryStudent(long num[],float score[], int n);
void  SortbyScore(long num[],float score[],int n);
void  SortbyName(long num[],float score[],int n);
void  SearchbyNum(long num[],float score[],int n);
void  AsSortbyNum(long num[],float score[],int n);
void  PrintScore(long num[],float score[],int n) ;
int main() {
	int choice;
	long num[STU_NUM];
	float score[STU_NUM];
	int n;
	printf("Input student number(n<30):\n");
	scanf("%d",&n);
u1:
	choice=Menu();
	switch(choice) {
		case 1:
			ReadScore(num,score,n);
			goto u1;
			break;
		case 2:
			AverSumofEveryStudent(num,score,n);
			goto u1;
			break;
		case 3:
			SortbyScore(num,score,n);
			goto u1;
			break;
		case 4:
			SortbyName(num,score,n);
			goto u1;
			break;
		case 5:
			SearchbyNum(num,score,n);
			goto u1;
			break;
		case 6:
			AsSortbyNum(num,score,n);
			goto u1;
			break;
		case 7:
			PrintScore(num,score,n);
			goto u1;
			break;
		case 0:printf("End of program!\n");
			break;
		default:
			printf("Input error!\n");
			goto u1;
			break;
	}

	return 0;
}
void  PrintScore(long num[],float score[],int n) {
	for(int i=0; i<n; i++) {
		printf("%ld\t%.0f\n",num[i],score[i]);
	}
}
void  AsSortbyNum(long num[],float score[],int n) {
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
void  SearchbyNum(long num[],float score[],int n) {
	printf("Input the number you want to search:\n");
	long find;
	int flag=0;
	scanf("%ld",&find);
	for(int i=0; i<n; i++) {
		if(num[i]==find) {
			printf("%ld\t%.0f\n",num[i],score[i]);
			flag=1;
			break;
		}

	}
	if(flag==0)printf("Not found!\n");
}
void  SortbyName(long num[],float score[],int n) {

	for(int i=0; i<n; i++) {

		for(int j=i+1; j<n; j++) {
			if(num[j]<num[i]) {
				float temp;
				temp=score[i];
				score[i]=score[j];
				score[j]=temp;
				long n;
				n=num[i];
				num[i]=num[j];
				num[j]=n;
			}
		}
	}
	printf("Sort in ascending order by number:\n");
	for(int i=0; i<n; i++) {
		printf("%ld\t%.0f\n",num[i],score[i]);
	}
}
void  SortbyScore(long num[],float score[],int n) {

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(score[j]>score[i]) {
				float temp;
				temp=score[i];
				score[i]=score[j];
				score[j]=temp;
				long n;
				n=num[i];
				num[i]=num[j];
				num[j]=n;
			}
		}
	}
	printf("Sort in descending order by score:\n");
	for(int i=0; i<n; i++) {
		printf("%ld\t%.0f\n",num[i],score[i]);
	}

}
void AverSumofEveryStudent(long num[],float score[], int n) {
	float sum=0;
	for(int i=0; i<n; i++)sum+=score[i];
	printf("sum=%.0f,aver=%.2f\n",sum,sum/n);
}
void  ReadScore(long num[], float score[], int n) {
	printf("Input student's ID, name and score:\n");
	for(int i=0; i<n; i++) {
		scanf("%ld%f",&num[i],&score[i]);
	}
}
int Menu(void) {
	printf("Management for Students' scores\n\
1.Input record\n\
2.Caculate total and average score of course\n\
3.Sort in descending order by score\n\
4.Sort in ascending order by number\n\
5.Search by number\n\
6.Statistic analysis\n\
7.List record\n\
0.Exit\n\
Please Input your choice:\n");
	int n;
	scanf("%d",&n);
	return n;
}
