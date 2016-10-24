#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N

//typedef struct {
//
//} ;


int main(){
int n;
scanf("%d",&n);

int*a=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
	int ret;
	scanf("%d",&ret);
	int max=i;
	for(int j=i-1;j>=0;j--){
		if(a[j]>ret)max=j;
		else if(a[j]<ret)break;
	}
	for(int f=i-1;f>=max;f--){
		a[f+1]=a[f];
	}
	a[max]=ret;
}

for(int i=0;i<n;i++){
	printf("%d ",a[i]);
}









return 0;
}

