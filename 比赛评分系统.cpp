#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
#define M 20
typedef struct player {
	unsigned num;
	float a[M];
	float result;
} PLAYER;
typedef struct jury {
	float a[N];
	float result;
} JURY;
float max(PLAYER,int);
float min(PLAYER,int);
void ath(PLAYER*,int);
void jud(JURY*,PLAYER*,int,int);
int main() {
	PLAYER * atheletes=NULL;
	JURY* judges=NULL;
	int m,n;
	printf("How many Athletes?\n");
	scanf("%d",&n);
	printf("How many judges?\n");
	scanf("%d",&m);
	atheletes=(PLAYER*)malloc(sizeof(PLAYER)*n);
	judges=(JURY*)malloc(sizeof(JURY)*m);
	/*-----------以上为动态分配成绩内存初始化-----------------*/
	for(int i=0; i<n; i++)atheletes[i].result=0;
	/*-----------以上为初始化内存段---------------------*/
	printf("Scores of Athletes:\n");
	for(int i=0; i<n; i++) {
		printf("Athlete %d is playing.\n",i+1);
		printf("Please enter his number code:\n");
		scanf("%u",&atheletes[i].num);
		for(int j=0; j<m; j++) {
			printf("Judge %d gives score:\n",j+1);
			scanf("%f",&atheletes[i].a[j]);
			judges[j].a[i]=atheletes[i].a[j];
			atheletes[i].result+=atheletes[i].a[j];
		}
		float low,high;
		high=max(atheletes[i],m);

		printf("Delete a maximum score:%.1f\n",high);
		low=min(atheletes[i],m);
		printf("Delete a minimum score:%.1f\n",low);
		atheletes[i].result-=high+low;
		atheletes[i].result/=m-2;
		printf("The final score of Athlete %d is %.3f\n",atheletes[i].num,atheletes[i].result);

	}
	/*-------选手排名----------*/
	ath(atheletes,n);

	/*-------评委排名----------*/
	jud(judges,atheletes,m,n);
	printf("Over!Thank you!\n");
	return 0;
}
void jud(JURY*a,PLAYER*b,int m,int n) {
	float sum;
	printf("Order of judges:\n");
	printf("order\tfinal score\tnumber code\n");
	for(int i=0; i<m; i++) {
		sum=0;
		for(int j=0; j<n; j++) {
			sum+=(b[j].a[i]-b[j].result)*(b[j].a[i]-b[j].result);
		}
		a[i].result=10-sqrt(sum/n);
	}
	int *p=(int*)malloc(sizeof(int)*m);
	for(int i=0;i<m;i++)p[i]=i;
	int max;
	for(int i=0;i<m;i++){
		max=p[i];
		for(int j=i+1;j<m;j++){
			if(a[max].result<a[p[j]].result)max=p[j];
		}
		if(max!=p[i]){
			int temp;
			temp=p[i];
			p[i]=p[max];
			p[max]=temp;
		}
	}
	for(int i=0;i<m;i++)printf("%5d\t%11.3f\t%6d\n",i+1,a[p[i]].result,p[i]+1);
}
void ath(PLAYER*a,int n) {

	int* p=(int*)malloc(sizeof(int)*n);
	printf("Order of Athletes:\n");
	for(int i=0; i<n; i++)p[i]=i;

	int max;
	for(int i=0; i<n; i++) {
		max=p[i];
		for(int j=i+1; j<n; j++) {
			if(a[max].result<a[p[j]].result)max=p[j];

		}
		if(max!=p[i]) {
			int temp;
			temp=p[i];
			p[i]=p[max];
			p[max]=temp;
		}
	}
	printf("order\tfinal score\tnumber code\n");
	for(int i=0; i<n; i++)printf("%5d\t%11.3f\t%6d\n",i+1,a[p[i]].result,a[p[i]].num);

}
float max(PLAYER a,int m) {
	float max=a.a[0];
	for(int i=1; i<m; i++) {
		if(a.a[i]>max) {
			max=a.a[i];
		}
	}
	return max;
}
float min(PLAYER a,int m) {
	float min=a.a[0];
	for(int i=1; i<m; i++) {
		if(a.a[i]<min) {
			min=a.a[i];
		}
	}
	return min;
}
