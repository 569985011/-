#include<stdio.h>
#include<stdlib.h>
#define N
/*error:
测试点	结果	用时(ms)	内存(kB)	得分/满分
	0	答案正确	1		256			12/12
	1	答案正确	16		2084		2/2
	2	答案正确	7		640			4/4
	3	答案正确	13		1152		3/3
	4	答案正确	13		944			2/2
	5	答案正确	13		896			2/2
		*/
		int deletedata(long long*,int*,int,int);
int main() {
	int n;
	scanf("%d",&n);
	long long a[100001];//存放元素 
	int b[100001];//预判可能是主元的地址集合 
	int c[100001];//确认是主元的地址集合 
	int umax=0,umin=0;
	int count=0;
	for(int i=0; i<n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]>=a[umax]) {
			umax=i;
			b[count++]=i;//主元一定一个比一个大
		} else if(a[i]<a[umin]) {
			umin=i;    //主元一定落在最小值到最大值之间
			count=0;	 
		}
	}
//	for(int i=0; i<count; i++)printf("%d-%lld ",b[i],a[b[i]]);
//	printf("\n");
	if(count){
	int cnt=0;
	int max=0;	
	for(int i=0; i<b[0]; i++) 
		if(a[i]>a[max])max=i;
	
	if(b[count-1]!=n-1){
		deletedata(a,b,count-1,n);
	}
	for(int i=count-1;i>0;i--) {
		if(b[i]==-1)continue;else c[cnt++]=b[i];
		if(a[b[i]]<a[max])break;
		if(b[i]-b[i-1]!=1)i=1+deletedata(a,b,i-1,b[i]);
		
	}
if(c[cnt-1]!=b[0]){if(b[0]!=-1)c[cnt++]=b[0];
}

	printf("%d\n",cnt);

	for(int i=cnt-1; i>=0;i--) {
	
		printf("%lld",a[c[i]]);
			if(i)printf(" ");
	}
printf("\n");
	}else printf("0\n\n");//若B数组为空则不存在主元。 
	
	return 0;
}

int deletedata(long long *a,int* b,int left,int right){//任意两个疑似主元的元素若其位置不相邻，则其中间的元素一定可以向左消除若干疑似元素。 
//	printf("left%d,right%d",b[left],right);
	int min=right-1;
	for(int i=right-2;i>b[left];i--){
		if(a[i]<a[min])min=i;
	}
//	printf(",min%d",min);
	for(int i=left;i>=0;i--){
		if(a[b[i]]>a[min]){b[i]=-1;
//		printf("*%d*",b[i]);
		}else return i;
	}
	return -1;
}
/*
	if(n>0)
	for(int i=umin; i<=umax; i++) {
		int flag=0;

		for(int j=max; j<i; j++) {
			if(a[j]>a[i]) {
				max=j;
				flag=1;
				break;
			}
		}
		if(!flag){max=i;
			if(min>i)
				for(int j=min;j>i;j--){
					if(a[j]<a[i]){
						min=j;flag=1;break;
					}
				}
			else if(min<i){min=n-1;for(int j=n-1;j>i;j--){
					if(a[j]<a[i]){
						min=j;flag=1;break;
					}
			}
			}
		}
		if(!flag) {
			b[cnt++]=i;
		}
	}*/
