#include<stdio.h>
#define MAX 64
/* 评测结果
时间 	结果 	得分 	题目 	编译器 	用时（ms） 	内存（MB） 	用户
2016-09-03 19:49 	答案正确 	25 	5-17 	gcc 	169 	8 	569985011
测试点结果
测试点 	结果 	得分/满分 	用时（ms） 	内存（MB）
测试点1 	答案正确 	15/15 	1 	1
测试点2 	答案正确 	2/2 	1 	1
测试点3 	答案正确 	2/2 	2 	1
测试点4 	答案正确 	6/6 	169 	8
查看代码*/
typedef struct st {
	int s[MAX];
	int top;
	char name;
}*ST;

long Pow(int x,int y);//计算x^y
void Creat(struct st ta[],int n);//初始化
void Hannuota(struct st ta[],long max);//主函数
int Top(ST a) ;
int Pop(ST a) ;
void Push(ST a,int x);

int main() {
	int n;
	scanf("%d",&n);
	struct st ta[3];
	Creat(ta,n);
	long max=Pow(2,n)-1;
//	printf("%lld\n",max);
	Hannuota(ta,max);


	return 0;
}
int Top(ST a) {
	return a->s[a->top];
};
int Pop(ST a) {
	return a->s[a->top--];
};
void Push(ST a,int x) {
	a->s[++a->top]=x;
};

long Pow(int x,int y) {
	long a=(int)x;
	for(int i=1; i<y; i++)a*=x;
	return a;
}


void Creat(struct st ta[],int n) {
	ta[0].name='a';
	ta[0].top=n-1;
//把所有圆盘从大到小放到柱子A上
	for(int i=0; i<n; i++)ta[0].s[i]=n-i;
	ta[1].top=ta[2].top=0;
	for(int i=0; i<n; i++)ta[1].s[i]=ta[2].s[i]=0;
//若n为偶数，按顺时针方向摆放ABC，否则逆时针
	if(n%2==0) {
		ta[1].name='b';
		ta[2].name='c';
	} else {
		ta[1].name='c';
		ta[2].name='b';
	}
}

void Hannuota(struct st ta[],long max) {
	for(int k=0,i=0; k<max; k++) {
		//按顺时针方向吧圆盘1从现在的位置移动到下一根柱子
		Push(&ta[(i+1)%3],Pop(&ta[(i%3)]));
//		ta[(i+1)%3].Push(ta[i%3].Pop());
		printf("%c -> %c\n",ta[i%3].name,ta[(i+1)%3].name);
		i++;
		//把另外两根柱子上的可以移动的圆盘移动到新的柱子上
		if(k++<max) {
			//吧非空柱子上的圆盘移动到空柱子上，当两根柱子都为空时，移动较小的圆盘
			if(Top(&ta[(i+1)%3])==0||
			        Top(&ta[(i-1)%3])>0&&
			        Top(&ta[(i+1)%3]) >Top(&ta[(i-1)%3])) {
				Push(&ta[(i+1)%3],Pop(&ta[(i-1)%3]));
//				ta[(i+1)%3].Push(ta[(i-1)%3].Pop());
				printf("%c -> %c\n",ta[(i-1)%3].name,ta[(i+1)%3].name);
			} else {
				Push(&ta[(i-1)%3],Pop(&ta[(i+1)%3]));
//				ta[(i-1)%3].Push(ta[(i+1)%3].Pop());
				printf("%c -> %c\n",ta[(i+1)%3].name,ta[(i-1)%3].name);
			}
		}

	}

}
