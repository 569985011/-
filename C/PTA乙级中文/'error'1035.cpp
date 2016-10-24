#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
测试点	结果	用时(ms)	内存(kB)	得分/满分
	0	答案正确	1			128			7/7
	1	答案正确	1			128			6/6
	2	答案正确	1			156			1/1
	3	答案正确	1			256			1/1
	4	答案错误	1			256			0/3
	5	答案正确	1			256			4/4
	6	答案正确	1			160			3/3
*/


/*构建2个函数，分别执行插入排序和归并排序；
依次执行两个程序，每次执行一步，执行后立即判断
是否与题目给出序列相同，相同则输出*/
int Insertion(int *insert,const int*order,const int len);//插入排序 
 int MergeSort(int *a,const int*order,int n);//归并排序 
int isit(int*a,const int*order,const int len);
void print(int*a,int len);
void Merge(int*,int,int,int);



int main() {
	int n;
	scanf("%d",&n);
	int insert[101]= {0};
	int merg[101]= {0};
	int order[101]= {0};
	int f;
	for(int i=0; i<n; i++) {
		scanf("%d",&f);
		insert[i]=f;
		merg[i]=f;
	}


	for(int i=0; i<n; i++)
		scanf("%d",&order[i]);


	if(!Insertion(insert,order,n))
	MergeSort(merg,order,n);


	return 0;
}

void Merge(int *a,int low,int mid,int high)
{
	int left=low,right=mid+1;
	int*b=(int*)malloc((high-low+1)*sizeof(int));
for(int i=low;i<=high;i++){
	if(left>mid)b[i-low]=a[right++];
	else if(right>high)b[i-low]=a[left++];
	else if(a[left]<a[right]){b[i-low]=a[left++];
	}else b[i-low]=a[right++];
}for(int i=low;i<=high;i++){
	a[i]=b[i-low];
}

}

int MergeSort(int *a,const int*order,int n)
{int flag=0;
for(int i=1;i<n;i*=2){
	
	int j;
	for( j=0;j+2*i<n;j+=2*i){
		Merge(a,j,j+i-1,j+2*i-1);
	}if(j+i<n)Merge(a,j,j+i-1,n-1);
	if(flag){printf("Merge Sort\n");print(a,n);return 1;
	}
	flag=isit(a,order,n);
} 
}
int Insertion(int *insert,const int*order,const int len) {
	int flag=0;int change=0;
	for(int i=1; i<len; i++) {
		if(change){printf("Insertion Sort\n");
		print(insert,len);return 1;
		} 
		if(insert[i]<insert[i-1]) {
			if(flag)change=1;
			int temp=insert[i];
			int j;
		for(j=i;j>=0;j--){
			if(insert[j-1]>temp){
				insert[j]=insert[j-1];
			}else{
				break;
			}
		}insert[j]=temp;
		}
		flag=isit(insert,order,len); 
	}
	return 0;
}


void print(int*a,int len) {
	for(int i=0; i<len; i++) {
		if(i)printf(" ");
		printf("%d",a[i]);
	}printf("\n");
}

int isit(int*a,const int*order,const int len) {

	for(int i=0; i<len; i++) {
		if(order[i]!=a[i]) {
//			print(a,len);
//			printf("\n");
			return 0;
		}
	}
	return 1;
}
