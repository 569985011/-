#include<stdio.h>
#include<stdlib.h>
#define N
struct harry{
	long long g;
	int s,k;
}reach,pay,ba1ck;
int main(){
scanf("%lld.%d.%d",&pay.g,&pay.s,&pay.k);
scanf("%lld.%d.%d",&reach.g,&reach.s,&reach.k);
//printf("\n%lld.%lld.%lld",pay.g,pay.s,pay.k);
//printf("\n%lld.%lld.%lld",reach.g,reach.s,reach.k);

{
int flag1=0,flag2=0;
	if(reach.k<pay.k){reach.s-=1;reach.k+=29;flag1=1;}
	if(reach.s<pay.s){reach.g-=1;reach.s+=17;flag2=1;}
	if(reach.g<pay.g){
		if(flag1){reach.s+=1;reach.k-=29;
		}
		if(flag2){reach.g+=1;reach.s-=17;
		}
		if(pay.k<reach.k){pay.s-=1;pay.k+=29;}
		if(pay.s<reach.s){pay.g-=1;pay.s+=17;}
		printf("-%lld.%d.%d",pay.g-reach.g,pay.s-reach.s,pay.k-reach.k);
	}else 
	printf("%lld.%d.%d",reach.g-pay.g,reach.s-pay.s,reach.k-pay.k);
}


return 0;
}
//15833 16785 952




//pay.k+=(pay.g*17+pay.s)*29;
//reach.k+=(reach.g*17+pay.s)*29;
//
//ba1ck.k=reach.k-pay.k;
//
//if(ba1ck.k<0){ba1ck.k*=-1;flag=1;}

