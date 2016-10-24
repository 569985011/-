#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 101
void print(int a){
	int flag=1;
	switch(a/100){
		case 0:flag=0;break;
		case 1:printf("yi ");break;
		case 2:printf("er ");break;
		case 3:printf("san ");break;
		case 4:printf("si ");break;
		case 5:printf("wu ");break;
		case 6:printf("liu ");break;
		case 7:printf("qi ");break;
		case 8:printf("ba ");break;
		case 9:printf("jiu ");break;
	}
	
	switch(a%100/10){
		case 0:if(flag)printf("ling ");break;
		case 1:printf("yi ");break;
		case 2:printf("er ");break;
		case 3:printf("san ");break;
		case 4:printf("si ");break;
		case 5:printf("wu ");break;
		case 6:printf("liu ");break;
		case 7:printf("qi ");break;
		case 8:printf("ba ");break;
		case 9:printf("jiu ");break;
	}
	switch(a%10){
		case 0:printf("ling");break;
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
	}
	printf("\n");
}


int main(){

    char n[N];
 	while((scanf("%s",n))!=EOF){
 		int num=0;
 	for(int i=0;i<strlen(n);i++){
 		num+=n[i]-'0';
	 }
	print(num);
 };


return 0;
}

