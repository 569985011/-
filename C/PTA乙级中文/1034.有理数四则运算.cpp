#include<stdio.h>
#include<stdlib.h>
/*
通过对求最大公约数函数的优化终于让程序 不再超时。
 
*/

void fun1(long long a1,long long b1);
long long divisor(long long b1,long long b2);//最大公约数
void add(long long a1,long long b1,long long a2,long long b2);
void jian(long long a1,long long b1,long long a2,long long b2);
void cheng(long long a1,long long b1,long long a2,long long b2);
void chu(long long a1,long long b1,long long a2,long long b2);
int main() {
	long long a1,b1,a2,b2,c1,c2;
	scanf("%lld/%lld%lld/%lld",&a1,&b1,&a2,&b2);
	

add(a1,b1,a2,b2);
jian(a1,b1,a2,b2);
cheng(a1,b1,a2,b2);
chu(a1,b1,a2,b2);

	return 0;
}
void add(long long a1,long long b1,long long a2,long long b2){

	fun1(a1,b1);
	printf(" + ");
	fun1(a2,b2);
	printf(" = ");
	fun1(a1*b2+a2*b1,b1*b2);
	printf("\n");
}
void jian(long long a1,long long b1,long long a2,long long b2){

	fun1(a1,b1);
	printf(" - ");
	fun1(a2,b2);
	printf(" = ");
	fun1(a1*b2-a2*b1,b1*b2);
	printf("\n");
}
void cheng(long long a1,long long b1,long long a2,long long b2){

	fun1(a1,b1);
	printf(" * ");
	fun1(a2,b2);
	printf(" = ");
	fun1(a1*a2,b1*b2);
	printf("\n");
}
void chu(long long a1,long long b1,long long a2,long long b2){

	fun1(a1,b1);
	printf(" / ");
	fun1(a2,b2);
	printf(" = ");
	if(a2==0)printf("Inf\n");
	else{
	
	fun1(a1*b2,b1*a2);
	printf("\n");
	}
}




void fun1(long long a1,long long b1) {
	int flag=0;
	if(b1<0){a1*=-1;b1*=-1;
	}
	if(a1<0){flag=1;a1*=-1;
	}
	long long c1=divisor(a1,b1);
	if(0==c1){printf("0");return;
	}
	a1/=c1;
	b1/=c1;

	if(!flag) {
		
		if(a1%b1==0)printf("%lld",a1/b1);
		else if(a1>b1)printf("%lld %lld/%lld",a1/b1,a1%b1,b1);
		else if(a1<b1)printf("%lld/%lld",a1,b1);
	}else{
		if(a1%b1==0)printf("(-%lld)",a1/b1);
		else if(a1>b1)printf("(-%lld %lld/%lld)",a1/b1,a1%b1,b1);
		else if(a1<b1)printf("(-%lld/%lld)",a1,b1);

	}
}


long long divisor(long long b1,long long b2) {//辗转相除 
	if(!b1||!b2)return 0;
	
	if(b1>b2){if(b1%b2==0)return b2;else return divisor(b1-b2,b2);
	}else{if(b2%b1==0)return b1;else return divisor(b2-b1,b1);
		
	}	

}
