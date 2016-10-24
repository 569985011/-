#include<stdio.h>
#include<stdlib.h>
#define N
int main(){
printf("Input m:\n");
int m;scanf("%d",&m);
int s=0;
for(int i=1;i<m;i++){
	if(m%i==0){
		s+=i;
	}
}if(s==m){
	printf("Yes!\n");
	for(int i=1;i<m;i++){
		if(m%i==0){
		if(i!=1)printf(",");
		printf("%d",i);}
	}
	
}else printf("No!\n");

return 0;
}

