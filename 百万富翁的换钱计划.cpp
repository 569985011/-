#include<stdio.h>

#define N 30
void poor(double*,int);
void rich(double*,int);
int main(){
double poormoney=0;
double richmoney=0;
int day;
poor(&poormoney,N);
rich(&richmoney,N);

printf("to Stranger: %.2f yuan\n",richmoney);
printf( "to Richman: %.2f yuan\n",poormoney);
return 0;
}
void poor(double*sum,int day){
	int eachday=100000;
	*sum=eachday*day;

}
void rich(double*sum,int day){
double each=0.01;
	for(int i=0;i<30;i++){
		if(!i){each=0.01;*sum=each;
		}else{
		each*=2;*sum+=each;}
	}


}
