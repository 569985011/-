#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int y,m,d,firstday,mayday,run,D,t;
scanf("%d %d %d",&y,&m,&d);
//计算某年第一天星期几
firstday=(365*y-364+y/4-y/100+y/400)%7;
//printf ("%d",firstday);//输出验证
//计算闰年
run=(y/4==0)&&(y/100!=0)||(y/400==0);

switch(m){//计算天数以及判断日期和月份的有效性
case 1:D=0;if (d>31)printf("day is error.");else printf("%d",(D+d+firstday)%7);break;
case 2:D=31;if (d>28+run)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 3:D=59+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 4:D=90+run;if (d>30)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 5:D=120+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 6:D=151+run;if (d>30)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 7:D=181+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 8:D=212+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 9:D=243+run;if (d>30)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 10:D=273+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 11:D=304+run;if (d>30)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
case 12:D=334+run;if (d>31)printf("day is error.");printf("%d",(D+d+firstday)%7);break;
default:printf("month is error");}
//mayday=firstday+1;

//system("pause");
	return 0;
}

