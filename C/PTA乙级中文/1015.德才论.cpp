#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int de;
	int cai;
	long num;
} STU;
int cmp(const void*c,const void*d){
	STU*a=(STU*)c;
	STU*b=(STU*)d;
	if(a->de+a->cai>b->de+b->cai){
		return -1;
	}else if(a->de+a->cai==b->de+b->cai){
		if(a->de>b->de)return -1;
		else if(a->de==b->de){
			if(a->num<b->num)return -1;
		}
	}
	return 1;
}
int main() {
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	STU*a=(STU*)malloc(n*sizeof(STU));
	STU*b=(STU*)malloc(n*sizeof(STU));
	STU*c=(STU*)malloc(n*sizeof(STU));
	STU*d=(STU*)malloc(n*sizeof(STU));
	int cnta=0,cntb=0,cntc=0,cntd=0;
	int de,num,cai;
	for(int i=0; i<n; i++) {//¶ÁÈ¡¡£ 
		scanf("%ld%d%d",&num,&de,&cai);
		if(de>=h) {
			if(cai>=h) {
				a[cnta].num=num;
				a[cnta].de=de;
				a[cnta++].cai=cai;
			} else if(cai>=l) {
				b[cntb].num=num;
				b[cntb].de=de;
				b[cntb++].cai=cai;
			} 
		}else if(cai>=l) {
				if(de>=cai) {
					c[cntc].num=num;
					c[cntc].de=de;
					c[cntc++].cai=cai;
				} else if(de>=l) {
					d[cntd].num=num;
					d[cntd].de=de;
					d[cntd++].cai=cai;
				}
			}
	}
	qsort(a,cnta,sizeof(STU),cmp);
	qsort(b,cntb,sizeof(STU),cmp);
	qsort(c,cntc,sizeof(STU),cmp);
	qsort(d,cntd,sizeof(STU),cmp);

	printf("%d\n",cnta+cntb+cntc+cntd); 
	for(int i=0;i<cnta;i++){
		printf("%ld %d %d\n",a[i].num,a[i].de,a[i].cai);
	}
		for(int i=0;i<cntb;i++){
		printf("%ld %d %d\n",b[i].num,b[i].de,b[i].cai);
	}
		for(int i=0;i<cntc;i++){
		printf("%ld %d %d\n",c[i].num,c[i].de,c[i].cai);
	}
		for(int i=0;i<cntd;i++){
		printf("%ld %d %d\n",d[i].num,d[i].de,d[i].cai);
	}
	return 0;
}

