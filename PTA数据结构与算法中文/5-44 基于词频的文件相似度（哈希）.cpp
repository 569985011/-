#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HashLenth 10007  //测试内存开销3MB，也就是不到1MB的数据个数。 
/*可能存在的坑“首先给出文件正文，最后在一行中只给出一个字符#”，所以我的scan()函数可能踩雷了。
暂时没想到怎么验证。。。*/
/* 评测结果
时间 	结果 	得分 	题目 	编译器 	用时（ms） 	内存（MB） 	用户
2016-08-30 18:26 	部分正确 	26 	5-44 	gcc 	86 	2 	569985011
测试点结果
测试点 	结果 	得分/满分 	用时（ms） 	内存（MB）
测试点1 	答案正确 	18/18 	2 	1
测试点2 	答案正确 	4/4 	2 	1
测试点3 	答案正确 	2/2 	1 	1
测试点4 	答案正确 	2/2 	1 	1
测试点5 	答案错误 	0/4 	86 	2
查看代码*/
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
	for(int i=1; i<=n; i++) {
		int flag=1;
		while(flag) {
			char*temp=scan();
			int len=strlen(temp);
			if(len==1&&temp[0]=='#')flag=0;
			else if(len>=3)Insert(i,temp);
		}
	}
	int m;
	if(scanf("%d",&m)==0)exit(1);
	while(m--) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(Same[a][b])printf("%.1f%%\n",Same[a][b]*100.0/(Sum[a]+Sum[b]-Same[a][b]));
		else printf("0.0%%\n");
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
	static char temp[11];
	static int Flag_br=1;
	int i=0;
	char c;
	do {
		c=getchar();
		if(c>='A'&&c<='Z') {
			if(i<10)temp[i++]=c-'A'+'a';
		} else if(c>='a'&&c<='z') {
			if(i<10)temp[i++]=c;
		} else if(!i&&Flag_br&&c=='#') {
			if((c=getchar())=='\n') {
				temp[i++]='#';
				Flag_br=1;
				break;
			} else {
				if(c>='A'&&c<='Z') {
					if(i<10)temp[i++]=c-'A'+'a';
				} else if(c>='a'&&c<='z') {
					if(i<10)temp[i++]=c;
				} else {
					Flag_br=0;
					break;
				}
			}
		} else if(c=='\n') {
			Flag_br=1;
			break;
		} else {
			Flag_br=0;
			break;
		}
	} while(1);
	temp[i]='\0';
//	printf("{%s}",temp);
	return temp;
}
