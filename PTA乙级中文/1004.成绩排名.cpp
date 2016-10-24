#include<stdio.h>
#include<stdlib.h>
#define N
typedef struct student{
	char name[20] ;//题目限定10个字符，但如果是中文字符就需要20字节
	char num[20] ;
	float score;
}STU;
int main(){
int n;
scanf("%d",&n);
STU* a=(STU*)malloc(sizeof(STU)*n);
for(int i=0;i<n;i++){
	scanf("%s%s%f",&a[i].name,&a[i].num,&a[i].score);
}
int max=0;
for(int i=0;i<n;i++){
	if(a[i].score>=a[max].score)max=i;
}
printf("%s %s\n",a[max].name,a[max].num);
int min=0;
for(int i=0;i<n;i++){
	if(a[i].score<=a[min].score)min=i;
}
printf("%s %s",a[min].name,a[min].num);
free(a);
return 0;
}

