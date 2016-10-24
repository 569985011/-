#include<stdio.h>
int main(){
	long a,b,k[2001]={0};char c;
	do{
		scanf("%ld%ld",&a,&b);
		k[b+1000]+=a;
	}while((c=getchar())!='\n');
	for(int i=1000;i<2001;i++){
		if(i>1000&&k[i]){k[i-1]=k[i]*(i-1000);
		k[i]=0;}
	}
	for(int i=999;i>=0;i--){
		if(k[i]){k[i+1]=k[i]*(i-1000);
		k[i]=0;}
	}
	int cnt=0;
	for(int i=2000;i>=0;i--){
		if(k[i]||i==1000){
			if(cnt)printf(" ");
			printf("%ld %ld",k[i],i-1000);
			cnt++;
		}
	}
	
}
