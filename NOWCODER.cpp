#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 1000



typedef struct ont{
int a;
struct ont *next;
} INT;
int prime(int,int*);
int readdate(INT*);
void print(INT*,int*); 

int main(){

INT*head=(INT*)malloc(sizeof(INT));
int max=readdate(head);

 int primes[N]={0};
 prime(max,primes);
print(head,primes);

return 0;
}
void print(INT*a,int*primes){
	
}

int prime(int max,int*a){
	int cnt=0;
	for(int i=0;i<=max;i++){
		if(i<2)a[i]=1;
		else if(i<4)a[i]=0;
		else 
		for(int j=2;j<i;j++){
			if(!a[j])if(i%j==0){
				a[i]=1;break;
			}
		}
		if(!a[i])cnt++;
	}
	return cnt;
} 
 
 int readdate(INT*a) {
 INT *head=a;
 int num;int max=0;
 	while(scanf("%d",&num)){
	a->a=num;
	if(num>max)max=num;
	a->next=(INT*)malloc(sizeof(INT));
	a=a->next;
}a->next=NULL;
a=head;//把链首返还给函数参数

return max;//返回链中最大数 

//while(a->next){
//	
//	printf("%d ",a->a);
//	a=a->next;
//}

 }
