#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isrose(int);
int isordinal(int,int);//·´ĞòÊı
int main(){
for(int i=1000;i<1112;i++){
	if(isordinal(i,i*9))printf("%d\n",i);
}

return 0;
}
int isrose(int num){
	int a,b,c,d;
	a=num/1000;
	b=num%1000/100;
	c=num%100/10;
	d=num%10;
	if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==num)return 1;
	else return 0;
}
int isordinal(int x,int y){
	int a,b=0;
	a=x;
	while(a){b=b*10+a%10;a/=10;
	}
	if(y==b)return 1;
	else return 0;
}

