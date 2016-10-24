#include<stdio.h>

#define N 10
int main(){
int ji[10]={0},ou[10]={0};
int j=0,k=0;
printf("Input 10 numbers:\n");
for(int i=0;i<10;i++){
	int a;
	scanf("%d",&a);
	if(a%2==0)ou[k++]=a;
	else ji[j++]=a;
}
int min=0;
for(int i=0;i<k;i++){
	for(int u=i+1;u<k;u++){
		if(ou[u]<ou[i]){
			int temp;
			temp=ou[i];
			ou[i]=ou[u];
			ou[u]=temp;
		}
	}
}
for(int i=0;i<j;i++){
	for(int u=i+1;u<j;u++){
		if(ji[u]<ji[i]){
			int temp;
			temp=ji[i];
			ji[i]=ji[u];
			ji[u]=temp;
		}
	}
}
int tegother[10];
printf("Output: ");
for(int i=0;i<10;i++){
	if(i)printf(",");
	if(i<j){
		tegother[i]=ji[i];
	}else{
		tegother[i]=ou[i-j];
	}printf("%d",tegother[i]);
	if(i==9)printf("\n");
}

return 0;
}

