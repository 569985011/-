#include<stdio.h>
   int main()
   {
       int score;
       char word;
       printf("Input simple:\n");
       scanf("%c", &word);
       if(word>='a'&&word<='z')
       		printf("It is an English character.");
       	else if(word>='A'&&word<='Z')
       		printf("It is an English character.");
       	else if(word>='0'&&word<='9')
       		printf("It is a digit character.");
       	else 
       		printf("It is other character.");
        return 0;
}
