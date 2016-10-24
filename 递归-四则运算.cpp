#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100
int cnt=0;
//typedef struct {
//
//} ;
void readdata(int*,char*);
int jisuan(int*,char*,int);
int jisuan2(int*,char*,int);
int main(){
int a[N];
char c[N];

readdata(a,c);
printf("%d",jisuan(a,c,0));
//printf("end cnt=%d",cnt); 

}
int jisuan(int* a,char*c,int i) {
	if(i>=cnt)return 0;
	int temp=jisuan2(a,c,i+1);
	if(c[i]=='+')return a[i]+temp;
	if(c[i]=='-')return a[i]-temp;
	return 0;
} 
int jisuan2(int *a,char*c,int i){
	if(i>=cnt)return 1;
	int temp=jisuan2(a,c,i+1);
	if(c[i]=='*')return a[i]*temp;
	if(c[i]=='/')return a[i]/temp;
	return 1;
}
void readdata(int*a,char*c){
	char k;
	scanf("%d",&a[0]);
	while(scanf("%c",&k)){
		if(k=='+'||k=='-'||k=='*'||k=='/'){
			c[cnt]=k;
			scanf("%d",&a[++cnt]);
			
		}else break;
	}
}
 
