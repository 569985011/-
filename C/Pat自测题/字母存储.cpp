#include<stdio.h>
#include<stdlib.h>
#define N
struct zimu{
	char a;
	struct zimu* link;
};

int find(int num,struct zimu*h);
int found(char key,struct zimu*h);


int main(){
struct zimu h1;
h1.a='a';
struct zimu h2;
h2.a='b';
struct zimu h3;
h3.a='c';
struct zimu h4;
h4.a='d';
struct zimu h5;
h5.a='c';
struct zimu h6;
h6.a='b';
struct zimu h7;
h7.a='a';
h1.link=&h2;
h2.link=&h3;
h3.link=&h4;
h4.link=&h5;
h5.link=&h6;
h6.link=&h7;
h7.link=NULL;
struct zimu*h=&h1;




int a;char c;
if(scanf("%d",&a)){
//printf("%d",a);
    find(a,h);
}else {
	scanf("%c",&c);
//	printf("%c",c);
	found(c,h);
}







return 0;
}

int find(int num,struct zimu*h){
	int flag=0;int cnt=0;
	while(h){
		
		if(num==cnt){flag=1;printf("%c\n",h->a);break;}
		h=h->link;cnt++;
		
	}if(!flag)printf("N\n");
	return 1;
}

int found(char key,struct zimu*h){
int num=0,result;int flag=0;
while(h){
	
if(h->a==key){
	result=num;flag=1;
}num++;
h=h->link;
}
if(!flag)printf("N\n");
else printf("%d\n",result);
return 1;
}
