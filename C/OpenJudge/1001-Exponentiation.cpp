#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************
*���ܣ����Լ���100����С����25���ڴη���Ҫ����߾���
*���ԣ�Openjudge1001
*˼·��ģ�±��Լ��㣬�ȸ�λ���˷��������С����Ӧ��������
*���ߣ�Chauncy523@gmail.com
*************************/
int* Power(int*R,int power);
void Caculation(int*r,int*R,int*s);

void Print(int*r,int decimal);
void fun(char*temp,int*R,int* decimal) {
	*decimal=0;//����С��λ��Ϊ0
	for(int i=strlen(temp)-1,j=0;; i--) {
		if(i<0) {//�����λ������Ϊ-1.
			R[j]=-1;
			break;
		}
		if(temp[i]=='.')*decimal=strlen(temp)-1-i;
		else R[j++]=temp[i]-'0';
	}

}
int main() {
	char temp[7];/*0.0<=R<=99.999*/

	int decimal;/*��¼С����λ��*/
	int power;/*�η� 1<=power<=25*/
	while(scanf("%s%d",temp,&power)==2) {
		int R[100]= {0}; /*ֻ���ڼ�¼��λ�ϵ�����ע�⣺�ӵ�λ����λ*/
		fun(temp,R,&decimal);/*��������R��ͳ��С��λ�� */
	
		Print(Power(R,power),power*decimal);
		printf("\n");
	}



	return 0;
}
int r[200]= {0};
int s[200]= {0};
int* Power(int*R,int power) {
	if(power==1)return R;
	Caculation(R,R,r);
	for(int i=3; i<=power; i++) {
		if(i%2==1) {
			Caculation(R,r,s);
		} else {
			Caculation(R,s,r);


		}
	}
	int *p;
	if(power%2==0)p=r;
	else p=s;
	
	return p;
}
void Caculation(int*a,int*b,int*c) {
	for(int i=0; i<200; i++)c[i]=0;/*���c����*/ 
	
	for(int i=0; b[i]!=-1; i++) {/*��ʽ����*/ 
		for(int j=0; a[j]!=-1; j++) {
			c[j+i]+=b[i]*a[j];
		}
	}

	for(int temp=0,i=0; i<200; i++) {/*����c���� */
		c[i]+=temp;
		temp=c[i]/10;
		c[i]%=10;
	}
	
	for(int i=200; i>0; i--) {/*���������ҵ����λ��������д��-1 */
		if(c[i-1]!=0) {
			c[i]=-1;
			break;
		}
	}
}
void Print(int*r,int decimal) { 
	if(*(r+1)!=-1) {
		Print(r+1,decimal-1);

	}	else if(decimal>0) {
		printf("0.");
		for(int i=1; i<decimal; i++)printf("0");
	}
	printf("%d",*r);
	if(decimal==0)printf(".");

}
