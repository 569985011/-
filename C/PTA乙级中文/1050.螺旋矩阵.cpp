#include<stdio.h>
#include<stdlib.h>
int leftflag,rightflag,topflag,bottomflag;

void readdata(int*,const int);
void right(int *b,int *a,int m,int n,int cnt);
void left(int *b,int *a,int m,int n,int cnt);
void bottom(int *b,int *a,int m,int n,int cnt);
void up(int *b,int *a,int m,int n,int cnt);

int main(){
int N;scanf("%ld",&N);


int m=N;
for(int i=1;i<N;i++){
	if(N%i==0){
		if(i-N/i>=0&&i-N/i<m-N/m)m=i;
	}
}
//printf("mÐÐ=%d,nÁÐ=%d",m,N/m);

int*a=(int*)malloc(N*sizeof(int));
readdata(a,N);
//printf("\n/***********/\n");
//for(int i=0;i<m;i++){
// for(int j=0;j<N/m;j++){
// 	if(j)printf(" ");
// 	printf("%d",a[i*N/m+j]);
// } printf("\n");
//} 
leftflag=0,rightflag=N/m,topflag=0,bottomflag=m;
int*b=(int*)malloc(N*sizeof(int));
right(b,a,m,N/m,0);
free(a);

//printf("\n/***********/\n");
for(int i=0;i<m;i++){
 for(int j=0;j<N/m;j++){
 	if(j)printf(" ");
 	printf("%d",b[i*N/m+j]);
 } printf("\n");
} 
return 0;
}
void readdata(int*b,const int num){
int a[10001]={0};
	for(int i=0;i<num;i++){
	int num;
	scanf("%d",&num);
	a[num]++;
	}
	int cnt=0;
	for(int i=10000;i>=0;i--){
		while(a[i]--){b[cnt++]=i;
		}
		if(cnt>=num)return;
	}
}
void right(int *b,int *a,int m,int n,int cnt){
	for(int i=leftflag;i<rightflag;i++){
		b[topflag*n+i]=a[cnt++];
		if(cnt>=m*n)return;
	}	topflag+=1;
		bottom(b,a,m,n,cnt);
} 
void bottom(int*b,int *a,int m,int n,int cnt){
	for(int i=topflag;i<bottomflag;i++){
		b[i*n+rightflag-1]=a[cnt++];
		if(cnt>=m*n)return;
	}   rightflag-=1;
	left(b,a,m,n,cnt);
} 
void left(int*b,int *a,int m,int n,int cnt){
		for(int i=rightflag-1;i>=leftflag;i--){
		b[bottomflag*n+i-n]=a[cnt++];
		if(cnt>=m*n)return;
	}	bottomflag-=1;
		up(b,a,m,n,cnt);
} 
void up(int*b,int *a,int m,int n,int cnt){
	for(int i=bottomflag-1;i>=topflag;i--){
		b[i*n+leftflag]=a[cnt++];
		if(cnt>=m*n)return;
	}	leftflag+=1;
	right(b,a,m,n,cnt);
} 
