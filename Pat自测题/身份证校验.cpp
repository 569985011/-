#include"stdlib.h"
#include"string.h"
#include"stdio.h"
char jiaoyan(char a[]){
	char y;int sum=0;
	int b[17];
	for(int j=0;j<17;j++){
		b[j]=a[j]-'0';
//		printf("ת���ַ�Ϊ���֣�");
//	printf("b(%d)=%d",j,b[j]);
//	printf("\n");}
	for(int i=0;i<17;i++){
		switch (i){
			case 0:sum=b[i]*7;break;
			case 1:sum+=b[i]*9;break;
			case 2:sum+=b[i]*10;break;
			case 3:sum+=b[i]*5;break;
			case 4:sum+=b[i]*8;break;
			case 5:sum+=b[i]*4;break;
			case 6:sum+=b[i]*2;break;
			case 7:sum+=b[i];break;
			case 8:sum+=b[i]*6;break;
			case 9:sum+=b[i]*3;break;
			case 10:sum+=b[i]*7;break;
			case 11:sum+=b[i]*9;break;
			case 12:sum+=b[i]*10;break;
			case 13:sum+=b[i]*5;break;
			case 14:sum+=b[i]*8;break;
			case 15:sum+=b[i]*4;break;
			case 16:sum+=b[i]*2;break;
		}}
	}//printf("\n���SUm=%d",sum);
	
	switch(sum%11){
		case 0:y='1';break;
		case 1:y='0';break;
		case 2:y='X';break;
		case 3:y='9';break;
		case 4:y='8';break;
		case 5:y='7';break;
		case 6:y='6';break;
		case 7:y='5';break;
		case 8:y='4';break;
		case 9:y='3';break;
		case 10:y='2';break;
	}
	//printf("\n���У����%c\n",y);
	return y;
} 

int main()
{
		int num;
	scanf("%d",&num);//���ö������ 
		char m[1000000][19];
	for(int i=0;i<num;i++){
		scanf("%s",&m[i]);
	}	
		//	{for(int i=0;i<num;i++)		printf("%s",m[i]);	}//�������� �����Ƿ�ɹ� 
	for(int i=0;i<num;i++){
			int len=strlen(m[i]);
		switch(len){
			case 15: //ת�� 
				for(int j=16;j>6;j--)//�м������ݵ�ǰ��λ�� 
					m[i][j]=m[i][j-2];
				m[i][6]='1';
				if(m[i][14]=='9')//����˳����ѡ��1800���1900�� 
					m[i][7]='8';
					else m[i][7]='9';
				m[i][17]=jiaoyan(m[i]);//����У���� 
				printf("%s\n",&m[i]);
				break;
			case 18:if(m[i][17]==jiaoyan(m[i]))
						printf("Valid\n");else printf("Invalid\n");
					break;//�ж�У���룬�Ǿ����Valid��break�����ִ����һ����䡣 
			default:printf("Invalid\n");break; 
		}
	}	
	return 0;
}
