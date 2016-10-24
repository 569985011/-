#include <stdlib.h>
#include <stdio.h>
/*

对于任意集合，分别计算左右两边最少应该取多少才能得到完整数据；即所有非单集合除最小的全取，+1，+零的个数 
另外一边取1 
*/
typedef struct {
int left;
int right;
} Gloves;

int main(){
	int n;
scanf("%d,[",&n);
Gloves*a=(Gloves*)malloc(sizeof(Gloves)*n);

int left=0,right=0;int left0=0,right0=0;int leftmin,rightmin;

for(int i=0;i<n;i++){
	scanf("%d%*c",&a[i].left);

}getchar();getchar();

for(int i=0;i<n;i++){
	scanf("%d%*c",&a[i].right);

}

for(int i=0;i<n;i++){
	if(a[i].left&&a[i].right){
		leftmin=a[i].left;rightmin=a[i].right;
		break;
	}
}
	
for(int i=0;i<n;i++){
		left+=a[i].left;
		if(a[i].left&&a[i].right&&a[i].left<leftmin)leftmin=a[i].left;
		if(a[i].left==0)left+=a[i].right;
	}left=left-leftmin+2;
//	 printf("left:%d-%d+1\n",left,leftmin);
for(int i=0;i<n;i++){
		right+=a[i].right;
		if(a[i].right&&a[i].left&&a[i].right<rightmin)rightmin=a[i].right;
		if(a[i].right==0)right+=a[i].left;
	}right=right-rightmin+2;
//	printf("right:%d-%d+1\n",right,rightmin);
	
if(left<right)
printf("%d\n",left);else printf("%d\n",right); 

//for(int i=0;i<n;i++){
//	printf("%d-%d ",a[i].left,a[i].right);
//}







return 0;
}

