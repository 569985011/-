#include<stdio.h>

#define N 10000
/*评测结果
2016-03-06 15:59     
测试点	结果	得分/满分 用时（ms）	内存（MB）要点提示
测试点1	答案正确  12/12   2  1   sample换个数字   
测试点2 答案正确   4/4    2  1   同类项合并时有抵消   
测试点3 答案正确   2/2    1  1   系数和指数取上限，结果有零多项式   
测试点4 答案正确   2/2    2  1   输入有零多项式和常数多项式   
*/
int main() {
	int a[N]= {0};
	int b[N]= {0};
	int c[N]= {0};
	int d[N]= {0};
	int i,m,f;
	scanf("%d",&i);
	while(i--) {
		scanf("%d %d",&m,&f);
		a[f]+=m;
	}
	scanf("%d",&i);
	while(i--) {
		scanf("%d %d",&m,&f);
		b[f]+=m;
	}
	for(int i=N-1; i>=0; i--) {
		if(a[i]) {
			for(int j=0; j<N; j++) {
				if(b[j]) {
					c[i+j]+=a[i]*b[j];
				}
			}
		}
	}
	int cnt=0;
	for(int i=N-1; i>=0; i--) {

		if(c[i]) {
			if(cnt)printf(" ");
			printf("%d %d",c[i],i);
			cnt++;
		}

	}
	if(!cnt)printf("0 0");

	for(int i=N-1; i>=0; i--)
		if(a[i])
			d[i]+=a[i];
	for(int j=0; j<N; j++)
		if(b[j])
			d[j]+=b[j];

printf("\n");

	 cnt=0;
	for(int i=N-1; i>=0; i--) {

		if(d[i]) {
			if(cnt)printf(" ");
			printf("%d %d",d[i],i);
			cnt++;
		}

	}
	if(!cnt)printf("0 0");
	return 0;
}

