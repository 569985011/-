#include<stdio.h>
#include<stdlib.h>
#define N
//����ע���桢�ۼۡ����ۡ����󣬣���û˵һ��������
typedef struct {
	float inventory;//���
	float price;//�ۼ�
	float unit;//����
} CK;
void pai(CK*a,int kind){
	for(int i=0;i<kind;i++){
		for(int j=i+1;j<kind;j++){
			if(a[j].unit>a[i].unit){
				CK p=a[i];
				a[i]=a[j];
				a[j]=p;
			}
		}
	}
}
int main() {
	int kind;//������Ŀ
	float need;//�г����������
	scanf("%d%f",&kind,&need);
	CK *a=(CK*)calloc(kind,sizeof(CK));
	for(int i=0; i<kind; i++) {
		scanf("%f",&a[i].inventory);
	}
	for(int i=0; i<kind; i++) {
		scanf("%f",&a[i].price);
		a[i].unit=1.0*a[i].price/a[i].inventory;
	}

	pai(a,kind);


	float sum=0;
	for(int i=0;need>0&&i<kind;i++){
  if(need>=a[i].inventory){
			need-=a[i].inventory;
			sum+=a[i].price;
		}else{

			sum+=need*a[i].unit;
			need-=need;
		}
	}
	printf("%.2f",sum);
	return 0;
}

