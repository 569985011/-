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
int main()//-----Ŀ�ģ����������������ж��Ƿ��ܹ��������Σ��ȱ������������3�����������2��һ�������1�����ܹ��������0�� 
{
  	 int a,b,c,d,e;
  	 scanf("%d %d %d",&a,&b,&c); 
  	 d=max(max(a,b),max(b,c));
  	 e=min(min(a,b),min(b,c));
  	 	if(e<=0)printf("�������������⣬����������������"); 
	    else{ if(d*2>=a+b+c)printf("0");//������������ 
	   	  	else{if(d==e)printf("3");//�ȱ�������
				else{if(a==b|b==c|a==c)printf("2");//����������
						 else printf("1");//һ�������� 
		 			}
				} 
		 	}
    return 0;
}
