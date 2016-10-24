#include<stdio.h>
#include<string.h>
#define N
int main(){
char a[160];
gets(a);int end=strlen(a)-1;
int cnt=0;
for(int i=strlen(a);i>=0;i--){
	if(a[i+1]==' '&&a[i]==' '){end=i-1;continue;}
	if(a[i]==' '&&i!=0){
		if(cnt)printf(" ");
		
		for(int j=i+1;j<=end;j++){
			printf("%c",a[j]);

		}
		end=i-1;
		cnt++;
	}
	else if(i==0){
		if(cnt)printf(" ");
		for(int j=i;j<=end;j++){
			printf("%c",a[j]);

		}
		
	}
}
return 0;
}

