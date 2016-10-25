#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1001
#define MaxSize 100
/*������
ʱ�� 	��� 	�÷� 	��Ŀ 	���� 	��ʱ(ms) 	�ڴ�(kB) 	�û�
10��25�� 15:57 	����ȷ 	20 	1054 	C (gcc 4.7.2) 	2 	256 	����ţ��
���Ե�
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	2	 		256		 	10/10
1 	����ȷ 	2 			256		 	5/5
2 	����ȷ 	2 			256		 	2/2
3 	����ȷ 	2 			256		 	3/3
*/

double Scan();

int main() {
	int n;
	scanf("%d",&n);
	double Sum=0;
	int Number=0;
	while(n--) {
		double temp=Scan();
		if(temp==ERROR)continue;
//		printf("{%lf}",temp);
		Sum+=temp;
		Number++;
	}
	if(Number==0)printf("The average of 0 numbers is Undefined");
	else if(Number==1)printf("The average of 1 number is %.2lf",Sum/Number);
	else printf("The average of %d numbers is %.2lf",Number,Sum/Number);

	return 0;
}

double Scan() {
	char temp[MaxSize];
	scanf("%s",temp);

	double num=0;
	int Fuhao=1;//����
	int point=0;//�Ƿ���С����
	double PointFlag=1;
	int Lenth=strlen(temp);

	for(int i=0; i<Lenth; i++) {
		if(temp[i]=='+'||temp[i]=='-')
			if(!i) {
				if(	temp[0]=='-')Fuhao=-1;
				continue;
			}

		if(temp[i]=='.')
			if(i&&(temp[i-1]>='0'&&temp[i-1]<='9')&&!point&&Lenth-i<4) {
				point=1;
				continue;
			}

		if(temp[i]>='0'&&temp[i]<='9') {
			if(point) {
				PointFlag*=0.1;
				num+=Fuhao*PointFlag*(temp[i]-'0');
			} else  {
				num*=10;
				num+=Fuhao*(temp[i]-'0');
			}
			continue;
		}
		printf("ERROR: %s is not a legal number\n",temp);
		return ERROR;
	}
	if(num>1000||num<-1000) {
		printf("ERROR: %s is not a legal number\n",temp);
		return ERROR;
	}
	return num;
}
