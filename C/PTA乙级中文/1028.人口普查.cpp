#include<stdio.h>
#include<stdlib.h>
#define N
typedef struct {
	char name[6];
	int y;
	int m;
	int d;
} PUC;
int Isqualified(PUC a);

int main() {
	int n;
	scanf("%d",&n);

	PUC*a=(PUC*)calloc(n,sizeof(PUC));
	int cnt=0;
	PUC max,min;
	for(int i=0; i<n; i++) {
		scanf("%s%d/%d/%d",a[i].name,&a[i].y,&a[i].m,&a[i].d);
		if(Isqualified(a[i])==1) {
			cnt++;
			max=a[i];
			min=a[i];
		}
	}
	for(int i=0; i<n; i++) {
	//	printf("%s %02d/%02d/%02d-%d\n",a[i].name,a[i].y,
	//	a[i].m,a[i].d,Isqualified(a[i]));
		if(Isqualified(a[i])) {
			if(a[i].y>max.y)max=a[i];

			if(a[i].y<min.y)min=a[i];

			if(a[i].y==max.y) {
				if(a[i].m>max.m)max=a[i];
				if(a[i].m<max.m)continue;
				if(a[i].m==max.m) {
					if(a[i].d>max.d)max=a[i];

				}
			}

			if(a[i].y==min.y) {
				if(a[i].m<min.m)min=a[i];
				if(a[i].m>min.m)continue;
				if(a[i].m==min.m) {
					if(a[i].d<min.d)min=a[i];

				}
			}
		}
		
	}
	if(cnt)printf("%d %s %s",cnt,min.name,max.name);
	else printf("0");
/*注意当数据全部无效时的输出*/

	return 0;
}


int Isqualified(PUC a) {
	int flag; 
	if(a.y>2014||a.y<1814){flag=0;}
	else if(a.y<2014&&a.y>1814){
		flag=1;}

	else if(a.y==2014) {
	
		if(a.m<9)flag=1;
		else if(a.m>9)flag=0;
		else {
			if(a.d<=6)flag=1;
			else flag=0;
		}
	} else if(a.y==1814) {
	
		if(a.m>9) {
			
			flag=1;
		} else if(a.m<9)flag=0;
		else {
		
			if(a.d>=6) {
			
				flag=1;
			}
			 else flag=0;
		}
	}
return flag;
}
