#include<stdio.h>
#include<math.h>
int isprime(int num);
int main(){
	int i,cnt,sum=0;
for(i=500,cnt=10;cnt;i--){
	if(isprime(i)){sum+=i;cnt--;printf("%6d",i);}
}
printf("\nsum=%d\n",sum);

return 0;
}
int isprime(int num){
	if(num<2)return -1;
	for(int i=2;i<sqrt((double)num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}
