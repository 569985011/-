#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N



void swap( int *pa, int *pb ) 
{
    int pt;
    pt = *pa, *pa = *pb, *pb = *pa;
}
int main(void)
{    
int n;int x,y;
scanf("%d",&n);
scanf("%d%d",&x,&y);
int xin=x,yin=y,xax=x,yax=y;
for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	if(x<xin)xin=x;
	if(x>xax)xax=x;
	if(y<yin)yin=y;
	if(y>yax)yax=y;
}
printf("%d %d %d %d\n",xin,yin,xax,yax);
}
