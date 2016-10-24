#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*

*/



int compare(const void* a,const void* b){
	long a1=*(long*)a;
	 long b1=*(long*)b;
	 
	return a1>b1?1:-1;
}
int main(){
int n;
scanf("%d",&n);
long*a=(long*)malloc(sizeof(long)*n);
for(int i=0;i<n;i++)scanf("%ld",&a[i]);
qsort(a,n,sizeof(long),&compare);
for(int i=0;i<n;i++){
	if(i)printf(" ");
	printf("%ld",a[i]);
}


return 0;
}


