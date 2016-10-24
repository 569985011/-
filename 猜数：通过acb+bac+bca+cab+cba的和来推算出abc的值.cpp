#include<stdio.h>
int Magic(int m);
int main(){
	int sum;int y;
	scanf("%d",&sum);
	y=Magic(sum);
	if(y==-1)printf("The sum you calculated is wrong!\n");
	else printf("The number is %d\n",y);
	return 0;
	
} 
int Magic(int m){
	int a,b,c;
	for(a=1;a<10;a++){
		if(122*a>m)break; 
		for(b=0;b<10;b++){
			if (a*122+b*212>m)break;
			for(c=0;c<10;c++){
				if(212*b+221*c+122*a>m)break;
				if(212*b+221*c+122*a==m)return a*100+b*10+c;

			}
		}
	}
	return -1;
}
