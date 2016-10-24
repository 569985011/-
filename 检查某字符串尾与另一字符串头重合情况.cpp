#include<stdio.h>
#include<string.h>
#define N 100
int main(){
	char a[N];int found;
	char b[N];int flag=1;
	scanf("%s%s",a,b);
	for(int i=0;i<strlen(a);i++){
		if(a[i]==b[0]){flag=0;found=i;
			for(int j=0;j<strlen(b)&&i<strlen(a);){
				if(a[i]!=b[j]){
					flag=1;break;
				}
				i++;j++;
			}
		}
	}
	if(flag==1)printf("unfound!");
	else if(!flag)for(int i=found;i<strlen(a);i++)printf("%c",a[i]);

}
