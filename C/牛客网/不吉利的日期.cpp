#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
int yearday(int y){
	if(y%4==0&&y%100!=0||y%400==0)return 1;
	else return 0;
}
int print(int firstday,int flag){
	switch (firstday){
		case 0:if(flag)printf("1 4 7");else printf("1 10");printf("\n");return 1;
		case 1:if(flag)printf("9 12");else printf("4 7");printf("\n");return 1;
		case 2:if(flag)printf("6");else printf("9 12");printf("\n");return 1;
		case 3:if(flag)printf("3 11");else printf("6");printf("\n");return 1;
		case 4:if(flag)printf("2 8");else printf("2 3 11");printf("\n");return 1;
		case 5:if(flag)printf("5");else printf("8");printf("\n");return 1;
		case 6:if(flag)printf("10");else printf("5");printf("\n");return 1;
		default:break;
	}
	return 0;
}

int main(){
    int n;
    int a[10000];
    a[2000]=6;//周日设为0 周一为1... 
	for(int i=2001;i<10000;i++) {
		a[i]=(a[i-1]+1+yearday(i-1) )%7;
	} 
 	while((scanf("%d",&n))!=EOF){
// 	printf("%d-firstday is %d\n",n,a[n]); 
 	print(a[n],yearday(n));
 };


return 0;
}

