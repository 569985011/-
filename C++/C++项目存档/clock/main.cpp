//#include<clock.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//#include<>

int main() {
	FILE*filename=fopen("badapple.txt","r");
	clock_t t=clock();

	if(filename) {
		while(!feof(filename)) {
			char temp[1024];
			while(fgets(temp,351,filename)&&strlen(temp)>6)
				printf("%s",temp);
			printf("%s",temp);
				for(int i=0,b=clock()/CLOCKS_PER_SEC;i<2;) { //完成1秒定时
				i=i-b;
				i=clock()/CLOCKS_PER_SEC;
			}
					system("cls");
		}
		fclose(filename);
	} else printf("ERROR!\n");


	return 0;
}

