#include<stdio.h>
#include<stdlib.h>
#define N
/*error:
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
	0	����ȷ	1		256			12/12
	1	����ȷ	16		2084		2/2
	2	����ȷ	7		640			4/4
	3	����ȷ	13		1152		3/3
	4	����ȷ	13		944			2/2
	5	����ȷ	13		896			2/2
		*/
		int deletedata(long long*,int*,int,int);
int main() {
	int n;
	scanf("%d",&n);
	long long a[100001];//���Ԫ�� 
	int b[100001];//Ԥ�п�������Ԫ�ĵ�ַ���� 
	int c[100001];//ȷ������Ԫ�ĵ�ַ���� 
	int umax=0,umin=0;
	int count=0;
	for(int i=0; i<n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]>=a[umax]) {
			umax=i;
			b[count++]=i;//��Ԫһ��һ����һ����
		} else if(a[i]<a[umin]) {
			umin=i;    //��Ԫһ��������Сֵ�����ֵ֮��
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
	}else printf("0\n\n");//��B����Ϊ���򲻴�����Ԫ�� 
	
	return 0;
}

int deletedata(long long *a,int* b,int left,int right){//��������������Ԫ��Ԫ������λ�ò����ڣ������м��Ԫ��һ����������������������Ԫ�ء� 
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
