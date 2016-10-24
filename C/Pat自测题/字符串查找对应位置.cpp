#include<stdio.h>
#include<string.h>
#define N 10
int main() {
	char a[N];
	int i=0;
	int flag=0;
	int result=0;
	char weekday[7][N]= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	printf("Please enter a string:\n");
	gets(a);
//	while(a[i++]!='\0');a[--i]='\0';
//printf("%d",strlen(a));
	for(int i =0; i<7; i++) {
		flag=0;

		for(int j=0;weekday[i][j]!='\0';j++)

		if(weekday[i][j]!=a[j])flag=1;
		
	if(flag==0&&strlen(a)==strlen(weekday[i])){
		printf("%s is %d\n",a,i);result=1;break;}
	}
	if(result==0)printf("Not found!\n");
	return 0;
}

