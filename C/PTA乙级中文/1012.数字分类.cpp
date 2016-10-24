#include<stdio.h>

#define N
int main(){
int A1=0,A2=0,A3=0,A4=0,A5=0;
int n,a,flag=1,cnt=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
	scanf("%d",&a);
	if(a%5==0&&a%2==0)A1+=a;
	if(a%5==1){A2+=a*flag;flag*=-1;}
	if(a%5==2)A3++;
	if(a%5==3){A4+=a;cnt++;	}
	if(a%5==4&&a>=A5)A5=a;
}
if(A1)printf("%d ",A1);else printf("N ");
if(A2)printf("%d ",A2);else printf("N ");
if(A3)printf("%d ",A3);else printf("N ");
if(A4)printf("%.1f ",1.0*A4/cnt);else printf("N ");
if(A5)printf("%d",A5);else printf("N");

return 0;
}

