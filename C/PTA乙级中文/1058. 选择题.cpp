/*WORNG! Wait for Change*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int score;
	int Numbers;
	int RightAnser;
	int WrongPerson;
} KeyToExercises[100];

void CreateKTE(int m);
void CheckStudents(int n,int m);


int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	CreateKTE(m);
	CheckStudents(n,m);
	struct node *Most=NULL;
	for(int i=0; i<m; i++) {
		if(KeyToExercises[i].WrongPerson) {
			if(Most&&Most->WrongPerson>=KeyToExercises[i].WrongPerson)continue;
			Most=&KeyToExercises[i];
		}
	}
	if(!Most) {
		printf("Too simple");
		return 0;
	}
	for(int i=0; i<m; i++) {
		if(Most->WrongPerson==KeyToExercises[i].WrongPerson) {
			if(Most!=&KeyToExercises[i])printf(" ");
			printf("%d %d",KeyToExercises[i].WrongPerson,i+1);
		}
	}
	return 0;
}


void CreateKTE(int m){
	for(int i=0;i<m;i++){
		scanf("%d%*d%d",&KeyToExercises[i].score,&KeyToExercises[i].Numbers);
		KeyToExercises[i].RightAnser=0;
		for(int j=0;j<KeyToExercises[i].Numbers;j++){//把选项abc当做字符相加，得到的字面值和答案个数结合比对成绩比较快捷 
			getchar();
			KeyToExercises[i].RightAnser+=getchar();
		}
		KeyToExercises[i].WrongPerson=0;
	}
}
void CheckStudents(int n,int m){
	for(int i=0;i<n;i++){
		int Score=0;
		for(int j=0;j<m;j++){
			int number,temp=0;
			scanf("(%d",&number);
			for(int k=0;k<number;k++){
				getchar();
				temp+=getchar();
			}
			getchar();
			if(temp==KeyToExercises[j].RightAnser)Score+=KeyToExercises[j].score;
			else{
				KeyToExercises[j].WrongPerson++;
			}
			
		}
		printf("%d\n",Score);
	} 
}

