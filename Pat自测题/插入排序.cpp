#include"stdio.h"
#define N 30
void pai(int a[]){
	int t;	
	for(int j=0;j<10;j++){
		for(int i=j+1;i<10;i++){
			if(a[i]<a[j]){t=a[j];a[j]=a[i];a[i]=t;}
		}
	}
}

int main(){
		int i=0;int b[N]={0};int cnt =0;char c;
		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",&b[0],&b[1],&b[2],&b[3],&b[4],&b[5],&b[6],&b[7],&b[8]);

	pai(b);
		scanf("%d",&b[0]);	
	pai(b);cnt=0;
	for(int i=0;i<10;i++){
		if(cnt)printf(",");
			printf("%d",b[i]);cnt++;}printf("\n");
	return 0;
} 
