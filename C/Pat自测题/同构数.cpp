#include<stdio.h>

#define N
int isomorphism(int m);
int main(){
	
for(int i=1;i<99;i++){
//	printf("test%d",i);
	if(isomorphism(i)==1)
	printf( "m=%3d\t\tm*m=%6d\n",i,i*i);

}

return 0;
}
int isomorphism(int m){
	int b=m*m,ten=10,flag=0;
	while(b%ten==m%ten&&m!=0){
	//	printf("test");
		flag=1;b/=10;m/=10;
	}
	if(m!=0)flag=0;
//	printf( "²âÊÔ£ºm=%3d\t\tm*m=%6d\n",m,m*m);
	return flag;
}
