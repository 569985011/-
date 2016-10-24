#include<stdio.h>
#include<stdlib.h> 
int max(int u,int m){
	int t;
	if(u>m)t=u;
	else t=m;
	return t;
	}
int min(int u,int m){
	int t;
	if(u<m)t=u;
	else t=m;
	return t;
}
int main()//-----目的：输入三个整数，判断是否能构成三角形，等边三角形则输出3；等腰则输出2；一般则输出1；不能构成则输出0； 
{
  	 int a,b,c,d,e;
  	 scanf("%d %d %d",&a,&b,&c); 
  	 d=max(max(a,b),max(b,c));
  	 e=min(min(a,b),min(b,c));
  	 	if(e<=0)printf("所给数据有问题，请输入大于零的整数"); 
	    else{ if(d*2>=a+b+c)printf("0");//不构成三角形 
	   	  	else{if(d==e)printf("3");//等边三角形
				else{if(a==b|b==c|a==c)printf("2");//等腰三角形
						 else printf("1");//一般三角形 
		 			}
				} 
		 	}
    return 0;
}
