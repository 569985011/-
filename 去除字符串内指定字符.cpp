#include<stdio.h>

#define N 10000
void Insert(char[],char);
int main(){
char a[N];
char word;
printf("Input a string:\n");
gets(a);
printf("Input a character:\n");
fflush(stdin);
word=getchar();
Insert(a,word);

return 0;
}
void Insert(char a[],char key){
	char b[N];int j=0;
	for(int i=0;a[i]!='\0';i++){
		
		if(a[i]!=key){
			b[j]=a[i];j++;
		}
	}
 printf("Results:%s\n",b);

}
