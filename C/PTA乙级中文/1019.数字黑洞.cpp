#include<stdio.h>

#define N
void pai(int*a,int*b,int*c,int*d){
	int u[4];
	u[0]=*a;u[1]=*b;
	u[2]=*c;u[3]=*d;
	for(int i=0;i<4;i++){
		for(int j=i;j<4;j++){
			if(u[j]>u[i]){
				int temp=u[j];
				u[j]=u[i];
				u[i]=temp;
			}
		}
	}
	*a=u[0];*b=u[1];
	*c=u[2];*d=u[3];
}
int main(){
int n,m;
scanf("%d",&n);
int a,b,c,d;
do{
	a=n/1000;
	b=n/100%10;
	c=n%100/10;
	d=n%10;
	if(a==b&&b==c&&c==d){
		printf("%04d - %04d = 0000",n,n);
		break;
	}
	pai(&a,&b,&c,&d);
	n=a*1000+b*100+c*10+d;
	m=d*1000+c*100+b*10+a;
	printf("%04d - %04d = %04d\n",n,m,n-m);
	n=n-m;
}while(n!=6174);

return 0;
}

