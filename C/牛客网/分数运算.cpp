#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*��������
ʱ������ 1000 ms �ڴ����� 32768 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
������в��ø�������ʾ����ʵ����������ζ�ž��ȶ�ʧ�������޷���ȷ��ʾ��1/3����

NowCoder���Ҫ����ܶ�������⣬
��Щ��Ŀ��������־��ȶ�ʧ����Ϊ��֮������֮ǧ����ܰ���ʵ��һ�׷����ļ�������
��������������ݡ�

ÿ������һ�У���������������һ����������м��ÿո������

���з������ĸ��Ϊ������30����������
��Ӧÿһ�����ݣ�������������ļ�������

Ҫ����������������������ĸ���ʡ�
*/
void add(int ,int,int,int);
void jian(int ,int,int,int);
void chen(int ,int,int,int);
void chu(int ,int,int,int);
void print(int,int);
int main(){
    int a1,b1,a2,b2;
    char c;
    while((scanf("%d/%d%d/%d %c",&a1,&b1,&a2,&b2,&c))!=EOF){
    	switch(c){
    		case '+':add(a1,b1,a2,b2);break;
    		case '-':jian(a1,b1,a2,b2);break;
    		case '*':chen(a1,b1,a2,b2);break;
    		case '/':chu(a1,b1,a2,b2);break;
    		default:printf("It's a wrong input!");break;
		}
		
	}
    
return 0;
}

void add(int a1,int b1,int a2,int b2){
	int a3,b3;
	a3=a1*b2+a2*b1;
	b3=b1*b2;
	print(a3,b3);
}
void jian(int a1,int b1,int a2,int b2){
	int a3,b3;
	a3=a1*b2-a2*b1;
	b3=b1*b2;
	print(a3,b3);
}
void chen(int a1,int b1,int a2,int b2){
	int a3,b3;
	a3=a1*a2;
	b3=b1*b2;
	print(a3,b3);
}
void chu(int a1,int b1,int a2,int b2){
	int a3,b3;
	a3=a1*b2;
	b3=b1*a2;
	print(a3,b3);
}
void print(int a,int b){
	if(a==0||b==0){
	printf("0\n");return;	
	}
//	if(a%b==0){printf("%d",a/b);return;}
	for(int i=b;i>0;i--){
		if(a%i==0&&b%i==0){
				a/=i;b/=i;
			printf("%d/%d\n",a,b);return;
		}
	}

}
