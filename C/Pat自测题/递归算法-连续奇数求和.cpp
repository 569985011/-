#include <stdio.h>
#include <math.h>
int main()
{int n;
scanf("%d",&n);
  int jisum(int a);
  int x;
  x=jisum(n);printf("%d\n",x);
  return 0;
}
int jisum(int b){
	int sum ;
	sum=(2*b-1);
	if(b==1)return 1.;
	else  sum+=jisum(b-1);
	return sum;
}
