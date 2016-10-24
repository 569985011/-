#include<stdio.h>
#include<stdlib.h>
typedef struct word {
	char a;
	struct word*link;
} W;

W*readdata(W*head);
W*min(W*head,char ed);

int  main() {
	W head;
	W*h=&head;
	h=readdata(h);
	h->link=(W*)malloc(sizeof(W));
	h=readdata(h->link);
//	h->link=&head;//±Õ»·

	char ed=' ';
	int cnt=0;
	while(h!=NULL){
	h=&head;
	h=min(h,ed);
	if(h!=NULL){
	if(cnt)printf(" ");
	printf("%c",h->a);
	cnt++;
	ed=h->a;}
	}

return 0;

}

W*readdata(W*head) {
	W*p=head;
	char c;
	do {
		c=getchar();
		p->a=c;
		c=getchar();
		if(c!='\n') {
			p->link=(W*)malloc(sizeof(W));
			p=p->link;
		} else {
			p->link=NULL;
			break;
		}
	} while(1);
	return p;
}

W* min(W*head,char ed) {
	int flag=0;
	W*min=NULL;
	W*h=head;
	while(h) {
		if(!flag) {
			if((h->a)>ed) {
				flag=1;
				min=h;
			}
		}
		else {
			if((h->a)>ed) {
				if((h->a)<(min->a)) {
					min=h;
				//	printf("*%c",min->a);
				}
			}
		}
		h=h->link;
	}

	return min;

}
