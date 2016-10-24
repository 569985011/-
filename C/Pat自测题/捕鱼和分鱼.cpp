#include<stdio.h>

int main(){
	int a=0,b=0,c=0,d=0,e,sum;int u;
int time =1;

for(e=255;1;e++){
	d=(e*5+1)/4;
	c=(d*5+1)/4;
	b=(c*5+1)/4;
	a=(b*5+1)/4;
	if((5*e+1)%4==0){//printf("e=%d\t",e);
		if((4*d)%5==1&&(5*d+1)%4==0){//printf("d=%d\t",d);
			if((4*c)%5==1&&(5*c+1)%4==0){//printf("c=%d\t",c);
				if(4*b%5==1&&(5*b+1)%4==0){//printf("b=%d\t",b);
					if(4*a%5==1)break;
					}
				}
			}
		}printf("x=%d\n",a);
	}
	sum=a+b+c+d+5*e+5;
	
printf("y=%d\n",sum);
return 0;
}

