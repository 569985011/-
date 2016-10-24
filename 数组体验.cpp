#include<stdio.h>
#include<stdlib.h>

int main(){
	int n=100;//指定最高次幂，也就是数组大小 
	int twice=2;
	int f[1000]={0};
	
	while(twice){
	//测试读入次数printf("twice\t");
		int m,x;
			scanf("%d %d",&m,&x);
				f[m]+=x;
	if(m==0)twice--;
	} 
//{{for(int cnt=0;cnt<n;cnt++)if (f[cnt])printf("%d=%d\n",cnt,f[cnt]);}}
//输出 
	int cnt=0; int u;
	for(u=n-1;u>1;u--){
		if(f[u]){
			if(f[u]==1){
				if(cnt==0)printf("x%d",u);
					else printf("+x%d",u);cnt++;}
			if(f[u]==-1){
				if(cnt==0)printf("-x%d",u);cnt++;}
			if(f[u]!=1&&f[u]!=1)
				if(cnt==0){
					if (f[u]>0){
						printf("%dx%d",f[u],u);cnt++;}
					if(f[u]<0){
						printf("%+dx%d",f[u],u);cnt++;}
				}else {printf("%+dx%d",f[u],u);cnt++;}
		}
	}
	if(f[1]){if(f[1]==1)
				if(cnt==0){printf("x");cnt++;}
					else {printf("+x");cnt++;}
			if(f[1]==-1)
				{printf("-x");cnt++;}
			if(f[1]!=1&&f[1]!=1)
				if(cnt==0){
					if (f[1]>0){
						printf("%dx",f[u]);}
					if(f[u]<0){
						printf("%+dx",f[u]);}
				cnt++;
				}else {printf("%+dx",f[u]);cnt++;}
	}
	if(f[0]){if(cnt||f[0]<0)printf("%+d",f[0]);else printf("%d",f[0]);cnt++;}
	if(!cnt)printf("0");
	return 0;
}
