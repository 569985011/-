#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N


int main(){

long long a[81],b[81],c[81];
a[1]=0;b[1]=0;c[1]=1;
a[2]=0;b[2]=1;c[2]=0;
a[3]=1;b[3]=0;c[3]=1;
int min=3;int from ,to; 
while((scanf("%d%d",&from,&to))!=EOF){
	if(to>min){//��̬��չ�����ų�������֤������Խ��Խ�࣬���ݿ�Ҳ��Խ��Խ����
	//��Ӧ�ģ��������ǾͲ��ü����ˡ� 
		for(int i=min+1;i<=to;i++){
			a[i]=a[i-1]+b[i-1];
			b[i]=c[i-1];
			c[i]=a[i];
		}
	}
	long long sum=0;
	for(int i=from;i<=to;i++){
		sum+=a[i]+b[i]+c[i];
	}printf("%lld\n",sum);
}


return 0;
}

