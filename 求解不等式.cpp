#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N
int main(){
printf("Input n:\n");
double n;
scanf("%lf",&n);
int m;double s;
for(m=0;1;m++){
	s=0;
	for(int i=m;i<=2*m;i++){
		s+=sqrt(i);
	}if(s>n)break;
}
printf("Result:m>=%d\n",m);
printf("s=%.2lf\n",s);
return 0;
}

