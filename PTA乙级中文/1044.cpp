#include<stdio.h>
#include<stdlib.h>
#define N
struct huoxing{
	char a[4];
	char b[4];
	int num;
	int flag;//Êý×ÖÎª1.×ÖÄ¸Îª0
};
int main(){
int n;scanf("%d",&n);
struct huoxing* a=(struct huoxing*)calloc(n,
sizeof(struct huoxing));


for(int i=0;i<n;i++){

	if(!(a[i].flag=(scanf("%d",&a[i].num))))
	scanf("%s%s",&a[i].a,&a[i].b);
	
	printf("test:%d-%d %s %s\n",a[i].flag,a[i].num,
	a[i].a,a[i].b);
}








return 0;
}

