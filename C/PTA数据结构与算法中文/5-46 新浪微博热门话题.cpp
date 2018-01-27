#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXLENTH 1000007
/*提交时间	状态	分数	题目	编译器	耗时	用户
2018/1/27 14:12:56	答案正确	30	7-46	C (gcc)	195 ms	569985011
测试点	提示	结果	耗时	内存
0	sample 并列热门；同一微博重复提到的话题只算1次	答案正确	2 ms	144KB
1	一个话题	答案正确	2 ms	128KB
2	分词不同，算2个不同的话题；同一微博可包含多个话题	答案正确	1 ms	128KB
3	最大N；最长微博；最长话题	答案正确	195 ms	1168KB*/
typedef struct node *Node;
struct node {
	char* KTitle;//整理后的话题
	int Times;//提到次数
	int LastTimeWhoPost;//最近一次提及它的是哪条微博（用于去重）
};
void Scan(int);
int HashKey(char*);
int Mod(int);
void Insert(int,char*);

Node Hash[MAXLENTH];//散列存储
Node Titles[MAXLENTH]; // 建立双索引
int SumofTitles=0;//话题总数

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++) {
		Scan(i);
	}

	Node MostTimes=Titles[0];
	int NumofMost=0;
	for(int i=1; i<SumofTitles; i++) {
//		printf("{%s--%d}",Titles[i]->KTitle,Titles[i]->Times);
		if(Titles[i]->Times>MostTimes->Times) {
			MostTimes=Titles[i];
			NumofMost=0;
		} else if(Titles[i]->Times==MostTimes->Times) {
			if(strcmp(Titles[i]->KTitle,MostTimes->KTitle)<0) {
				MostTimes=Titles[i];
			}
			++NumofMost;
		}
	}
	if(MostTimes->KTitle[0]>='a'&&MostTimes->KTitle[0]<='z')MostTimes->KTitle[0]+='A'-'a';
	printf("%s\n%d",MostTimes->KTitle,MostTimes->Times);
	if(NumofMost) {
		printf("\nAnd %d more ...",NumofMost);
	}
	return 0;
}
void Scan(int NumofWeibo) {
	char temp[141];//每行给出一条英文微博，其长度不超过140个字符
//	getchar();
	gets(temp);
	int Flag_Jin=0;
	char title[141];
	int Flag_Space=1;
//	printf("{S-%s}\n",temp);
	for(char*i=temp,*j=title; *i!='\0'; i++) {
		if(Flag_Jin==1) {
			switch(*i) {
				case '#':
					while(*(j-1)==' ')--j;
					*j='\0';
					if(strlen(title)>0)//两个连续的#是空话题，不予计数 
						Insert(NumofWeibo,title);
					Flag_Jin=0;					
					j=title;
					break;
				case 'a'...'z':
				case '0'...'9':
					*j++=*i;
					Flag_Space=0;
					break;
				case 'A'...'Z':
					*j++=*i-'A'+'a';
					Flag_Space=0;
					break;
				default:
					if(Flag_Space==0) {
						*j++=' ';
						Flag_Space=1;
					}
					break;
			}
		} else if(*i=='#') {
			Flag_Jin=1;
			Flag_Space=1;
		}
	}
}
int HashKey(char*K) {
//	printf("&");
	unsigned int n=0;
	while(*K) {
		n+=*K-'a';
		n<<=5;
//		printf("(%d)",n);
		K++;
	}
//	printf("*-*");
	return n;
}
int Mod(int n) {
	while(n<0)n+=MAXLENTH;
	return n%MAXLENTH;
}
void Insert(int NumofWeibo,char*t) {//比较后插入散列表并更新话题原型
//	printf("{I-%s}",t);
	int Key=HashKey(t);
	int i=0,j=0;
	for( ; i<=MAXLENTH/2; i++) {
		j=Mod(Key+i);
		if(Hash[j]) {
			if(strcmp(t,Hash[j]->KTitle)==0) {
				if(Hash[j]->LastTimeWhoPost==NumofWeibo)return;
				++Hash[j]->Times;
				Hash[j]->LastTimeWhoPost=NumofWeibo;
//				printf("{add:%s}",Hash[j]->KTitle);
			}
		} else break;
		j=Mod(Key-i);
		if(Hash[j]) {
			if(strcmp(t,Hash[j]->KTitle)==0) {
				if(Hash[j]->LastTimeWhoPost==NumofWeibo)return;
				++Hash[j]->Times;
				Hash[j]->LastTimeWhoPost=NumofWeibo;
//				printf("{add:%s}",Hash[j]->KTitle);
			}
		} else break;
	}
	if(i>MAXLENTH/2) {
//		printf("NOT ENOUGH SPACE");
		exit(1);
	}
	Hash[j]=(Node)malloc(sizeof(struct node));
	Hash[j]->KTitle=(char*)malloc(strlen(t));
	strcpy(Hash[j]->KTitle,t);
	Hash[j]->Times=1;
	Hash[j]->LastTimeWhoPost=NumofWeibo;
	Titles[SumofTitles++]=Hash[j];//把新加入的元素在哈希表中的地址保存进数组。方便遍历。
//	printf("{new:%s}",Hash[j]->KTitle);
}
