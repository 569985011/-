#include<stdio.h>
int cnt;
void Chline(char ch, int column, int row);
int main(){
char ch;int column;int row;
printf("input a char:\n");
scanf("%c",&ch);
printf("input column and row:\n");
scanf("%d%d",&row,&column);
cnt=row;
Chline(ch,column,row);

return 0;
}
void Chline(char ch, int column, int row){
	printf("%c",ch);//printf("\tcnt=%d\t",cnt);
	if(row==1&&column!=1)printf("\n");
	
	if(row>1)Chline(ch,column,row-1);
	else if(column>1)Chline(ch,column-1,cnt);

	
} 
