#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
struct student{
	int num;
	int aver;
}stu[3];
//{{1,90,80,70}，{2,85,75,95}，{3,88,84,65}}
int main(){
char a[N];
int b;
if(scanf("%d",&b)!=1)scanf("%s",a);
/*这里后一个scanf可以从缓冲区直接独处数据*/

stu[0].num=1;stu[0].aver=(90+80+70)/3;
stu[1].num=2;stu[1].aver=(85+75+95)/3;
stu[2].num=3;stu[2].aver=(88+84+65)/3;
if(strcmp(a,"max")==0)printf("%d",2);
else if(b>0&&b<4){
	printf("%d",stu[b-1].aver);
}else printf("0");
return 0;
}

