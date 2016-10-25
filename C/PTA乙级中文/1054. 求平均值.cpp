#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1001
#define MaxSize 100
/*评测结果
时间 	结果 	得分 	题目 	语言 	用时(ms) 	内存(kB) 	用户
10月25日 15:57 	答案正确 	20 	1054 	C (gcc 4.7.2) 	2 	256 	书生牛犊
测试点
测试点 	结果 	用时(ms) 	内存(kB) 	得分/满分
0 	答案正确 	2	 		256		 	10/10
1 	答案正确 	2 			256		 	5/5
2 	答案正确 	2 			256		 	2/2
3 	答案正确 	2 			256		 	3/3
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
	int Fuhao=1;//正负
	int point=0;//是否有小数点
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
