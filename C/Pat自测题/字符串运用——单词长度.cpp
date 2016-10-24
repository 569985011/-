#include <stdio.h>
#include<string.h>
#define N 100
#define M 100
int main(){
		char a[N][M];int u=0;int cnt=0;
	for(int i=0;a[i-1][u-1]!='.';i++){
		scanf("%s",&a[i]);
		u=strlen(a[i]) ;
		cnt++;
		}
		
	for(int i=0;cnt--;i++){
		if(cnt)printf("%d",strlen(a[i]));else printf("%d",strlen(a[i])-1);
		if(cnt)printf(" ");
	}
}
