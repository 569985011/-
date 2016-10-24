#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_Lenth 4400000
#define Min(a) (((a)>='A'&&(a)<='Z')?((a)+32):(a))

typedef struct node*Node;
struct node {
	char *Topic;
	int Reached;
};


Node List[MAX_Lenth]= {0};

int  numList=0;

void scan(int);
void fun();
int stricmp(const char*a,const char*b) {
	
	for(; *a!='\0'; a++,b++) {
		if(Min(*a)!=Min(*b))break;
	}
	
	return Min(*a)-Min(*b);

}
int cmp(const void*a,const void*b) {
	Node x=*(Node*)a;
	Node y=*(Node*)b;
	int temp=stricmp(x->Topic,y->Topic);
	if(temp)return temp;
	else 	return x->Reached-y->Reached;
}
int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		scan(n);
	}
	qsort(List,numList,sizeof(Node),cmp);
//for(int i=0;i<numList;i++)printf("{%s}",List[i]->Topic);
	fun();

	return 0;
}

void fun() {
	Node Hot=List[0];
	int Most=1;
	int binglie=0;
	Node This=List[0];
	int Num=1;
	for(int i=1; i<numList; i++) {
		if(stricmp(This->Topic,List[i]->Topic)) {
			if(Num==Most) {
			
				binglie++;
			} else if(Num>Most) {
				binglie=0;
				Most=Num;
				Hot=This;
			}
			This=List[i];
			Num=1;
		} else if(This->Reached!=List[i]->Reached) {
			if(strcmp(List[i]->Topic,This->Topic)<0){
					This=List[i];
				}else
				This->Reached=List[i]->Reached;			
			Num++;
		}
	}
	if(Num>Most) {
		binglie=0;
		Most=Num;
	} else if(Num==Most) {
		binglie++;
	}
	printf("%s\n%d",Hot->Topic,Most);
	if(binglie)printf("\nAnd %d more ...",binglie);
}

void scan(int h) {//
	char weibo[141];
	getchar();
	gets(weibo);
	int len=strlen(weibo);
	for(int flag=0,index,i=0; i<len; i++) {
		if(weibo[i]=='#') {
			if(!flag) {
				flag=1;
				index=i;
				continue;
			} else {
				List[numList]=(Node)malloc(sizeof(struct node));
				List[numList]->Topic=(char*)malloc(sizeof(char)*(i-index));
				List[numList]->Reached=h;
				int k=0;//保留前40个字符 
				for(int j=index+1; j<i&&k<40; j++) {
					if((weibo[j]>='A'&&weibo[j]<='Z')||weibo[j]==' '||//weibo[j]+='a'-'A';
					        (weibo[j]>='a'&&weibo[j]<='z'))//如果需要也可以保留空格
						List[numList]->Topic[k++]=weibo[j];
				}
				List[numList++]->Topic[k]='\0';
				flag=0;
			}

		}
	}
}
