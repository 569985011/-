/*自测-4 Have Fun with Numbers   (20分)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9,
 with no duplication. Double it we will obtain 246913578, 
 which happens to be another 9-digit number consisting exactly the numbers from 1 to 9,
  only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. 
That is, double a given number with kkk digits, 
you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, 
or "No" if not. Then in the next line, print the doubled number.

Sample Input:

1234567899
Sample Output:

Yes
2469135798*/
#include<stdio.h>
#include<string.h>
int readdata(int*a,int *a2){
	char b[30];
	gets(b);

	for(int i=0;i<strlen(b);i++){
		a[i]=b[i]-'0';
	}int swap=0;
	for(int i=strlen(b)-1;i>=0;i--){
		a2[i]=a[i]*2+swap;swap=0;
		if(a2[i]>9){swap=a2[i]/10;a2[i]%=10;
		}
		
	}if(swap){//如果最高位发生了进位则弹出No； 
		printf("No\n%d",swap);
		for(int i=0;i<strlen(b);i++)printf("%d",a2[i]);
		return 0;
	}
	return strlen(b);
} 
int main() {
int a[21];int a2[21];
int lenth=readdata(a,a2);
if(!lenth)return 0;
	int u[10]={0};
	for(int i=0;i<lenth;i++){
		u[a[i]]+=1;
		u[a2[i]]-=1;
	}int flag=0;
	for(int i=0;i<10;i++){
		if(u[i]){flag=1;break;
		}
	}
	if(flag)printf("No\n");else printf("Yes\n");
	for(int i=0;i<lenth;i++)printf("%d",a2[i]);
	return 0;
}

