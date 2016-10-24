#include<stdio.h>

#define N 100
int main(){
char a[N],b[N];
gets(a);
gets(b);
int cnt=0;
for(int i=0;a[i]!='\0';){
	if(a[i]==b[0]){
		int flag=0;
		for(int j=0;b[j]!='\0';j++){
			if(a[i++]!=b[j])flag=1;
		}
		if(flag==0)cnt++;
	}else i++;
}
if(!cnt)printf("No\n");else
printf("%d\n",cnt);
return 0;
}

