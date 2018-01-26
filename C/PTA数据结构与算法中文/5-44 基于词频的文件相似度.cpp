#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HashLenth 10007  //测试内存开销3MB，也就是不到1MB的数据个数。 

/* 评测结果
提交时间	状态	分数	题目	编译器	耗时	用户
2018/1/26 17:49:32	答案正确	30	7-44	C (gcc)	75 ms	569985011
测试点	提示	结果	耗时	内存
0	sample	答案正确	2 ms	244KB
1	同一文件内重复出现的单词不重复计算；太长的单词只考虑前10个字母	答案正确	2 ms	244KB
2	完全不同	答案正确	2 ms	256KB
3	完全相同	答案正确	2 ms	152KB
4	最大N和M；有1个文件包含了全部单词；有1个单词出现在所有文件里	答案正确	75 ms	2032KB*/
typedef struct node *Node;
struct node {
	char*Word;
	int Reached[101];
	int Times;
};
Node Hash[HashLenth]= {0};
int Same[101][101]= {0};
int Sum[101]= {0};
int n;

int Mod(int);
char*scan();
void Insert(int ,char*);
int HashKey(char*);
void Refresh(Node,int);

int main() {
	scanf("%d",&n);
	for(int j=0; j<n; j++) {
		while(1) {
			char*temp=scan();
			if(temp) {
				if(temp[0]=='#') {
//					printf("+EOF+");
					break;
				}
				Insert(j+1,temp);
			}
		}
	}
	int m;
	scanf("%d",&m);
	while(m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)printf("100.0%%\n");//测试了老半天才发现这个坑。。。 
		else
			printf("%.1f%%\n",Same[a][b]*100.0/(Sum[a]+Sum[b]-Same[a][b]));

	}
	return 0;
}

void Refresh(Node N,int h) {
	if(N->Reached[N->Times]==h)return;//同一个文件里面出现的重复单词不累加
	++Sum[h];//文件词汇量+1
//	printf("[Used");
	N->Reached[++N->Times]=h;
	for(int i=0; i<N->Times; i++) {//所有包含此字符串的文件彼此Same++
//		printf("*");
		++Same[N->Reached[i]][h];
		++Same[h][N->Reached[i]];
	}
//	printf("]");
}

int HashKey(char*K) {//尽量不让他抱团
	int temp=(K[0]-'a')*32*32+(K[1]-'a')*32+K[2]-'a';
	temp*=HashLenth;
	temp/=27482;//26*32*32+26*32+26
	return temp;
}

int Mod(int Num) {
	while(Num<0)Num+=HashLenth;
	return Num%HashLenth;
}
void Insert(int h ,char*K) {
	int Key=HashKey(K);
	int flag;
	int i;
	for( i=0; i<=HashLenth/2; i++) {
		flag=Mod(Key+i*i);
		if(!Hash[flag])break;
		else if(!strcmp(Hash[flag]->Word,K)) {
			Refresh(Hash[flag],h);
			return ;
		}
		flag=Mod(Key-i*i);
		if(!Hash[flag])break;
		else if(!strcmp(Hash[flag]->Word,K)) {
			Refresh(Hash[flag],h);
			return ;
		}
	}
	if(i>HashLenth/2) {//实践证明平台的词汇量并不多
		exit(1);//	printf("ERROR:HashLenth is not enouth!\n");
	}
//	printf("[NEW]");
	++Sum[h];//对该文件词汇量+1
	Hash[flag]=(Node)malloc(sizeof(struct node));
	Hash[flag]->Word=(char*)malloc(sizeof(char)*strlen(K));
	strcpy(Hash[flag]->Word,K);
	Hash[flag]->Times=0;
	Hash[flag]->Reached[0]=h;
}


char*scan() {
//	printf("#");
	static char temp[11];
	static int Flag_br=0;
	int i=0;
	char c;
	while(1) {
		c=getchar();
		switch(c) {
			case '#' :
				if(Flag_br==1) {
					c=getchar();
					if(c=='\n') {
						temp[0]='#';
						temp[1]='\0';
						return temp;
					}
				}
			default:
				switch(c) {
					case 'a'...'z':
						if(i<10)
							temp[i++]=c;
						break;
					case 'A'...'Z':
						if(i<10)
							temp[i++]=c-'A'+'a';
						break;

					default:
						if(c=='\n')Flag_br=1;
						else Flag_br=0;

						temp[i]='\0';
						if(i>2) {
//							printf("{%s}",temp);
							return temp;
						} else {
//							printf("{}");
							return NULL;
						}
						break;
				}
				break;
		}
	}
}
