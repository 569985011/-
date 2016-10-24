#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 50
int main(){
char c[N];int i=0,cnt=0;
printf("Please input a string end by #:\n");
do{c[i++]=getchar();
cnt++;
}while(c[i-1]!='#');
int space=0,newline=0,other=0;
for(int j=0;j<cnt-1;j++){
	if(c[j]==' ')space++;
	else if(c[j]=='\n')newline++;
	else other++;
}
printf("space: %d,newline: %d,others: %d\n"\
,space,newline,other);
return 0;
}

