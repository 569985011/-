#include<stdio.h>
#define MAX 64
/* ������
ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-09-03 19:49 	����ȷ 	25 	5-17 	gcc 	169 	8 	569985011
���Ե���
���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	15/15 	1 	1
���Ե�2 	����ȷ 	2/2 	1 	1
���Ե�3 	����ȷ 	2/2 	2 	1
���Ե�4 	����ȷ 	6/6 	169 	8
�鿴����*/
typedef struct st {
	int s[MAX];
	int top;
	char name;
}*ST;

long Pow(int x,int y);//����x^y
void Creat(struct st ta[],int n);//��ʼ��
void Hannuota(struct st ta[],long max);//������
int Top(ST a) ;
int Pop(ST a) ;
void Push(ST a,int x);

int main() {
	int n;
	scanf("%d",&n);
	struct st ta[3];
	Creat(ta,n);
	long max=Pow(2,n)-1;
//	printf("%lld\n",max);
	Hannuota(ta,max);


	return 0;
}
int Top(ST a) {
	return a->s[a->top];
};
int Pop(ST a) {
	return a->s[a->top--];
};
void Push(ST a,int x) {
	a->s[++a->top]=x;
};

long Pow(int x,int y) {
	long a=(int)x;
	for(int i=1; i<y; i++)a*=x;
	return a;
}


void Creat(struct st ta[],int n) {
	ta[0].name='a';
	ta[0].top=n-1;
//������Բ�̴Ӵ�С�ŵ�����A��
	for(int i=0; i<n; i++)ta[0].s[i]=n-i;
	ta[1].top=ta[2].top=0;
	for(int i=0; i<n; i++)ta[1].s[i]=ta[2].s[i]=0;
//��nΪż������˳ʱ�뷽��ڷ�ABC��������ʱ��
	if(n%2==0) {
		ta[1].name='b';
		ta[2].name='c';
	} else {
		ta[1].name='c';
		ta[2].name='b';
	}
}

void Hannuota(struct st ta[],long max) {
	for(int k=0,i=0; k<max; k++) {
		//��˳ʱ�뷽���Բ��1�����ڵ�λ���ƶ�����һ������
		Push(&ta[(i+1)%3],Pop(&ta[(i%3)]));
//		ta[(i+1)%3].Push(ta[i%3].Pop());
		printf("%c -> %c\n",ta[i%3].name,ta[(i+1)%3].name);
		i++;
		//���������������ϵĿ����ƶ���Բ���ƶ����µ�������
		if(k++<max) {
			//�ɷǿ������ϵ�Բ���ƶ����������ϣ����������Ӷ�Ϊ��ʱ���ƶ���С��Բ��
			if(Top(&ta[(i+1)%3])==0||
			        Top(&ta[(i-1)%3])>0&&
			        Top(&ta[(i+1)%3]) >Top(&ta[(i-1)%3])) {
				Push(&ta[(i+1)%3],Pop(&ta[(i-1)%3]));
//				ta[(i+1)%3].Push(ta[(i-1)%3].Pop());
				printf("%c -> %c\n",ta[(i-1)%3].name,ta[(i+1)%3].name);
			} else {
				Push(&ta[(i-1)%3],Pop(&ta[(i+1)%3]));
//				ta[(i-1)%3].Push(ta[(i+1)%3].Pop());
				printf("%c -> %c\n",ta[(i+1)%3].name,ta[(i-1)%3].name);
			}
		}

	}

}
