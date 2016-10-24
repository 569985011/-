#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
struct zuobiao {
	int x;
	int y;
	int num;
};
/*error:估计是要求一次性输入多组数据分别执行并输出吧
当前代码只能执行一次*/
void readdata(int*u,int m,int n,struct zuobiao *b) ;
void paixu(struct zuobiao *b,int);
int cost(int,int,int,int);
int main() {
	int m;//1<=m<=20,表示m行
	int n;//1<=n<=20表示n列
	int k;//1<=k<=1000，表示k个单位时间
	struct zuobiao b[401];
	while(scanf("%d%d%d",&m,&n,&k)!=EOF){

	/*理论上是不会有超过400个有效数据的*/
	int u=0;
	
	
	readdata(&u,m,n,b);
	int cnt=0;int beginx=b[0].x,beginy=0;

	for(int i=0; i<u; i++) {
		if(i) {
			beginx=b[i-1].x;
			beginy=b[i-1].y;
		}
		k-=cost(beginx,beginy,b[i].x,b[i].y);
		   if(k>=0)
			   {cnt+=b[i].num;k+=b[i].y+1;
			   }
		else break;

	}
printf("%d",cnt);
}
	return 0;
}

int cost(int beginx,int beginy,int tox,int toy) {
	int x=(beginx+tox)-beginx*2;
	if(x<0)x*=-1;
//	printf("%d-",x);
	int y=(beginy+toy)-beginy*2;
	if(y<0)y*=-1;
//	printf("%d-",y);
	return(x+y+toy+1);
}

void readdata(int *u,int m,int n,struct zuobiao *b) { /*读取数据*/
	int num;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++) {
			scanf("%d",&num);
			if(num) {
				b[*u].x=i;
				b[*u].y=j;
				b[*u].num=num;
				(*u)++;
			}
		}

	paixu(b,*u);
}
void paixu(struct zuobiao *b,int u) {
	for(int i=0; i<u-1; i++) {
		int max=i;
		for(int j=i+1; j<u; j++) {
			if(b[j].num>b[max].num)max=j;
		}
		if(max!=i) {
			int x=b[max].x;
			int y=b[max].y;
			int num=b[max].num;
			b[max].x=b[i].x;
			b[max].y=b[i].y;
			b[max].num=b[i].num;
			b[i].x=x;
			b[i].y=y;
			b[i].num=num;
		}
	}
	//for(int f=0;f<u;f++){
//	printf("%d*%d-%d,",b[f].x,b[f].y,b[f].num);
//}
}
