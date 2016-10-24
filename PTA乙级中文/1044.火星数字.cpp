#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void huo(int);
int earth(char* a);

int main() {
int num;char b[5];char a[8];char c[5];
	int flag;
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	flag=scanf("%d",&num);
	if(!flag){
	gets(a);
		if(strlen(a)==7){
			int i;flag=2;
			for(i=0;a[i]!=' ';i++)b[i]=a[i];
			b[i]=0;
			for(int j=i+1;j<=strlen(a);j++)c[j-i-1]=a[j];
		}else{
			flag=3;
		}
			
	}	
	if(flag==1){huo(num);}
	else if(flag==2){printf("%d",earth(b)+earth(c));}
	else if(flag==3){printf("%d",earth(a));}
	printf("\n");
	}
	return 0;
}

int earth(char* a) {
	int sum=0;
	if(strcmp(a,"tret")==0)sum=0;
	else if(strcmp(a,"jan")==0)sum=1;
	else if(strcmp(a,"feb")==0)sum=2;
	else if(strcmp(a,"mar")==0)sum=3;
	else if(strcmp(a,"apr")==0)sum=4;
	else if(strcmp(a,"may")==0)sum=5;
	else if(strcmp(a,"jun")==0)sum=6;
	else if(strcmp(a,"jly")==0)sum=7;
	else if(strcmp(a,"aug")==0)sum=8;
	else if(strcmp(a,"sep")==0)sum=9;
	else if(strcmp(a,"oct")==0)sum=10;
	else if(strcmp(a,"nov")==0)sum=11;
	else if(strcmp(a,"dec")==0)sum=12;
	else if(strcmp(a,"tam")==0)sum=13;
	else if(strcmp(a,"hel")==0)sum=26;
	else if(strcmp(a,"maa")==0)sum=39;
	else if(strcmp(a,"huh")==0)sum=52;
	else if(strcmp(a,"tou")==0)sum=65;
	else if(strcmp(a,"kes")==0)sum=78;
	else if(strcmp(a,"hei")==0)sum=91;
	else if(strcmp(a,"elo")==0)sum=104;
	else if(strcmp(a,"syy")==0)sum=117;
	else if(strcmp(a,"lok")==0)sum=130;
	else if(strcmp(a,"mer")==0)sum=143;
	else if(strcmp(a,"jou")==0)sum=156;
	return sum;

}

void huo(int n) {
	if(n<=12) {
		switch(n) {
			case 0:
				printf("tret");
				break;
			case 1:
				printf("jan");
				break;
			case 2:
				printf("feb");
				break;
			case 3:
				printf("mar");
				break;
			case 4:
				printf("apr");
				break;
			case 5:
				printf("may");
				break;
			case 6:
				printf("jun");
				break;
			case 7:
				printf("jly");
				break;
			case 8:
				printf("aug");
				break;
			case 9:
				printf("sep");
				break;
			case 10:
				printf("oct");
				break;
			case 11:
				printf("nov");
				break;
			case 12:
				printf("dec");
				break;
		}
	} else {
		switch(n/13) {
			case 1:
				printf("tam");
				break;
			case 2:
				printf("hel");
				break;
			case 3:
				printf("maa");
				break;
			case 4:
				printf("huh");
				break;
			case 5:
				printf("tou");
				break;
			case 6:
				printf("kes");
				break;
			case 7:
				printf("hei");
				break;
			case 8:
				printf("elo");
				break;
			case 9:
				printf("syy");
				break;
			case 10:
				printf("lok");
				break;
			case 11:
				printf("mer");
				break;
			case 12:
				printf("jou");
				break;
		}
		if(n%13) {
			printf(" ");
			switch(n%13) {
				case 1:
					printf("jan");
					break;
				case 2:
					printf("feb");
					break;
				case 3:
					printf("mar");
					break;
				case 4:
					printf("apr");
					break;
				case 5:
					printf("may");
					break;
				case 6:
					printf("jun");
					break;
				case 7:
					printf("jly");
					break;
				case 8:
					printf("aug");
					break;
				case 9:
					printf("sep");
					break;
				case 10:
					printf("oct");
					break;
				case 11:
					printf("nov");
					break;
				case 12:
					printf("dec");
					break;
			}
		}
	}

}
