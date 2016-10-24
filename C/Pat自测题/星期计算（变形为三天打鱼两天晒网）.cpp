#include<stdio.h>


int days(int y,int m,int d);
int main() {
	int y,d,m;
	int theday;
	int check;
	check=scanf("%4d%*c%2d%*c%2d",&y,&m,&d);
	if(check!=3)printf("Invalid input");
	else {
		int firstday;
		firstday=(y-1900)%20/5;
		theday=days(y,m,d);
		if(theday==-1)printf("Invalid input");
		else if((theday+1+firstday)%5<3){
				printf("He is working");}
			else printf("He is having a rest");

	}

	return 0;
}
int days(int y,int m,int d) {
	if(y<1900||d<1)return -1;
	int flag=0;
	int day;
	if(y%4==0&&y%100!=0||y%400==0)flag=1;
	else flag=0;
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(d>31)return -1;
			break;
		case 2:
			if(d>28+flag)return -1;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(d>30)return -1;
			break;
		default:
			return -1;
			break;
	}
	switch(m) {
		case 1:
			day=d;
			break;
		case 2:
			day=d+31;
			break;
		case 3:
			day=d+59+flag;
			break;
		case 4:
			day=d+90+flag;
			break;
		case 5:
			day=d+120+flag;
			break;
		case 6:
			day=d+151+flag;
			break;
		case 7:
			day=d+181+flag;
			break;
		case 8:
			day=d+212+flag;
			break;
		case 9:
			day=d+243+flag;
			break;
		case 10:
			day=d+273+flag;
			break;
		case 11:
			day=d+304+flag;
			break;
		case 12:
			day=d+334+flag;
			break;
		default:
			day=-1;
			break;
	}
	return day;
}
