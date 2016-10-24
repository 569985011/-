#include<stdio.h>
int main(){
	int a,b;int swap(int,int); 
	scanf("%d/%d",&a,&b);
	int u;
	u=swap(a,b);
	printf("%d/%d",a/u,b/u);
	return 0;
}
int swap(int a,int b){
	a>b?(a=a%b):(b=b%a);
	if(a==0)return b;
	else if(b==0)return a;
	else swap(a,b);
}
