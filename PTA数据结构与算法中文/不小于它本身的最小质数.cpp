#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node *Node;
struct node{

};

int Isprim(int a){
	if(a<2)return 0;
	if(a==2||a==3)return 1;

	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)return 0;
	}
	return 1;
}

int main(){
int n;
scanf("%d",&n);
while(!Isprim(n))++n;
printf("%d",n);



	return 0;
}

