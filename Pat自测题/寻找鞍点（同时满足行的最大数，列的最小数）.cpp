#include<stdio.h>
int main()
{
  	int n[100][100]={0};
  		int m,g;
	scanf("%d %d",&m,&g);
		int i,j;
  	for(i=0;i<m;i++){
  		for(j=0;j<g;j++){
  			scanf("%d",&n[i][j]);
		  }
	  }
//	测试数组读入 {  	for(i=0;i<m;i++){for(j=0;j<m;j++){printf("%d\t",n[i][j]);}printf("\n");}printf("___shuzu___\n"); }
	int max[100]={0};
	for(i=0;i<m;i++){
			int uax=0;
		for(j=0;j<g;j++){
			if((n[i][j])>uax){uax=n[i][j];max[i]=j;}
		}
	}
//测试各行最大值	{for(i=0;i<m;i++)printf("%d\t",max[i]);printf("\n_____________\n");	}
//产生了m个各行的最大值，找出该列的最小值，
	int cnt=0;int cvt=0;
	for(i=0;i<m;i++){
		int v;int ret=1;
		for(v=0;v<m;v++){
			if(n[v][max[i]]<n[i][max[i]])ret=0;
		}
		if(ret){printf("Point:a[%d][%d]==%d\n",i,max[i],n[i][max[i]]);cvt=1;}
	}
	if(!cvt)printf("No Point\n");	 
    return 0;
}
