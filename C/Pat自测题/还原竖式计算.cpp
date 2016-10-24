#include<stdio.h>
#define N 532
int main(){
int x,y,z;

for(x=0;x<10;x++){
	if(x*100>N)break;
	for(y=0;y<10;y++){
		if(x*100+y*110>N)break;
		for(z=0;z<10;z++)
		if(x*100+y*110+12*z==N)
		printf("X=%d,Y=%d,Z=%d\n",x,y,z);
	}
} 

return 0;
}

