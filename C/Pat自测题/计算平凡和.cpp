#include<stdio.h>
#include<math.h>
int main(){
	printf("please input x and y:\n");
	double x,y;
	scanf("%lf%*c%lf",&x,&y);
//	pow(x,y);
	printf("result=%.2f\n",pow(x,2)+pow(y,2));
} 
