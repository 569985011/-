#include "stdio.h"
#include"string.h"
#define N 5
int main()
{
    char a[N][1000]={0},lin[1000]={0};
		 scanf("%s",&a[0]);
    for(int i=1;i<N;i++){
    	scanf("%s",&lin);
    	for(int j=i;j>0;j--){
   				int v=strcmp(a[j-1],lin);
   			if(v<0){
			   strcpy(a[j],a[j-1]);if(j==1){strcpy(a[0],lin);break;}}
   			else {strcpy(a[j],lin);break;}
			}
	}
	for(int j=0;j<N;j++){
		printf("%s\n",a[j]);
	}
    return 0;
}
