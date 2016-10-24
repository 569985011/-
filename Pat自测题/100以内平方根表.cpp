#include<stdio.h>
#include<math.h>
#define N
int main(){


for(int i=0;i<10;i++){
	printf("%7d",i);
}printf("\n");
for(int i=0;i<10;i++){
	printf("%d",i);
	for(int j=0;j<10;j++){
		printf("%7.3f",sqrt(i*10+j));
	}
	printf("\n");
}
return 0;
}

