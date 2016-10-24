#include<stdio.h>

#define N

int main(){
for(int i=100;i<=200;i++){
	if(i%4==2){
		if(i%7==3){
			if(i%9==5){
				printf("%d\n",i);break;
			}
		}
	}
}
return 0;
}

