#include<stdio.h>
#include<string.h>//��������Ĵ�����û������ͷ�ļ���
#define N 80
int main()
{
	char str[N];
	int i,len;
	char temp;
	printf("Input a string:\n");
	gets(str);
	len=strlen(str)-1;//�޸Ĵ˴�����
	
	for(i=0;i<(len/2);i++)
	{   //printf("%c-%c ",str[i],str[len-i]);
	/*     ������������������������ڵ�һ�ν�������Ͱѡ�\0�������˿�ͷ��
	��͵��º������str�䵽��һ����ֹͣ��        */
		temp=str[i];
		str[i]=str[len-i];
		str[len-i]=temp;
		
	}
	printf("Inversed results:\n");
	puts(str);
	return 0;
}
