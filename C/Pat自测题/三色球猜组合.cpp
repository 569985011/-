#include<stdio.h>

#define N
int Fun (void);
int main(){
	printf("The result:\n");
Fun();

return 0;
}
int Fun (void){
	int sum=0;
	for(int red=1;red<4;red++){
		for(int white=1;white<6;white++){
			int black=8-red-white;
			printf("red:%4d white:%4d black:%4d\n",red,white,black);
			sum++;
		}
	}
	printf("sum=%4d\n",sum);
}
