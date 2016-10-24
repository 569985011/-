#include<stdio.h>

#define N 10
int swap(int a,int b){
	if(a==0||b==0)return -1;else{
	a>b?(a=a%b):(b=b%a);
	if(a==0)return b;
	else if(b==0)return a;
	else swap(a,b);}
}
int main(){
printf("Input 10 numbers:\n");
int a[N]={0};
for(int i=0;i<N;i++){
	scanf("%d",&a[i]);
}
int maxPos=0,minPos=0;
for (int i=1; i<N; i++)
    {
       if (a[i] > a[maxPos])
        {
          
           maxPos = i;
        }
        if (a[i] < a[minPos])
       {
           ;
            minPos = i;
        }
     }
     printf("maxNum=%d\n",a[maxPos]);
     printf("minNum=%d\n",a[minPos]);
    int result;
	 result=swap(a[maxPos],a[minPos]);
    if(result!=-1) printf("%d",result);
return 0;
}

