#include <stdio.h>
#include <math.h>
int main() {
//	printf("Please enter the number:\n");
	int n;	int m;
	int sum=0,a=0,b=0,c=0,d=0,e=0,f=0;
scanf("%d",&n);
	m=n/100000;
	switch (m) {
		default:
		case 10:
			a=n-1000000;
			sum+=a*0.01;
		case 9:
		case 8:
		case 7:
		case 6:
			b=n-a-600000;
			sum+=b*0.015;
		case 5:
		case 4:
			c=n-a-b-400000;
			sum+=c*0.03;
		case 3:
		case 2:
			d=n-c-a-b-200000;
			sum+=d*0.05;
		case 1:
			e=n-a-b-c-d-100000;
			sum+=e*0.075;
		case 0:
			f=n-a-b-c-d-e;
			sum+=f*0.1;
			break;
	}
	printf("bonus=%d",sum);
	return 0;
}
