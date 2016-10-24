#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*分数运算
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
计算机中采用浮点数表示所有实数，但这意味着精度丢失。例如无法精确表示“1/3”。

NowCoder最近要处理很多金融问题，
这些账目不允许出现精度丢失，因为差之毫厘谬之千里。你能帮他实现一套分数的计算器吗？
输入包含多组数据。

每组数据一行，包含两个分数和一个运算符，中间用空格隔开。

其中分子与分母均为不大于30的正整数。
对应每一组数据，输出两个分数的计算结果。

要求输出最简分数，即分子与分母互质。
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
