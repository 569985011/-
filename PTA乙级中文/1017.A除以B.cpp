#include<stdio.h>
#include<string.h>
#define N
int main(){
char a[1001];

int b;
scanf("%s%d",&a,&b);int r=0;int k,cnt=0;
//printf("a=%s;strlen(a)=%d;b=%d\n",a,strlen(a),b);
for(int i=0;i<strlen(a);i++){
	k=(a[i]-'0'+r*10);

	r=k%b;
	if(k/b!=0)cnt++;
	if(cnt)
	printf("%d",k/b);

}
if(!cnt)printf("0");
printf(" %d",r);


return 0;
}

