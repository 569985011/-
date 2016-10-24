#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 99999
/*注意读入的数字是要由右往左计算位数 
*/
void char2int (char*ca,int *a);
void ji(int a,int b);
void ou(int ,int);
int max(int ,int);

int main(){
char ca[N]={0},cb[N]={0};
scanf("%s %s",ca,cb);
int a[N]={0},b[N]={0};

char2int(ca,a);
char2int(cb,b);
int i=max(strlen(ca),strlen(cb));
for(--i;i>=0;i--){
	if(i%2==0){//奇数 
		ji(a[i],b[i]);
	}else{
		ou(a[i],b[i]);
	}
}
//for(int i=0;i<strlen(ca);i++)printf("%d",a[i]);
//printf("\n");
//for(int i=0;i<strlen(cb);i++)printf("%d",b[i]);

return 0;
}

int max(int a,int b){
	if(a>=b)return a;
	else return b;
}
void ou(int a,int b){
	if(b-a>=0)	printf("%d",b-a);
	else printf("%d",b+10-a);
}

void ji(int a,int b){
	char sum;
	switch((a+b)%13){
		case 0:sum='0';break;
			case 1:sum='1';break;
			case 2:sum='2';break;
			case 3:sum='3';break;
			case 4:sum='4';break;
			case 5:sum='5';break;
			case 6:sum='6';break;
			case 7:sum='7';break;
			case 8:sum='8';break;
			case 9:sum='9';break;
			case 10:sum='J';break;
			case 11:sum='Q';break;
			case 12:sum='K';break;
	}
	printf("%c",sum);	
}

void char2int (char*ca,int *a){
	for(int i=strlen(ca);i;i--){
	a[strlen(ca)-i]=ca[i-1]-'0';
}
}
