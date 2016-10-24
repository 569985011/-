#include <stdio.h>
#include<stdlib.h>
/* ������ ʱ�� 	��� 	�÷� 	��Ŀ 	������ 	��ʱ��ms�� 	�ڴ棨MB�� 	�û�
2016-08-30 09:37 	������ȷ 	17 	5-26 	gcc 	45 	3 	569985011
���Ե��� ���Ե� 	��� 	�÷�/���� 	��ʱ��ms�� 	�ڴ棨MB��
���Ե�1 	����ȷ 	15/15 	1 	1
���Ե�2 	����ȷ 	2/2 	1 	1
���Ե�3 	����ȷ 	8/8 	46 	3
�鿴����*/
typedef struct node *Node;
struct node {
	char Information[11];
	int priority;
};
struct {
	Node heap[100002];
	int Numbers;
} Heap;

void Put();
void Get();


int main() {
	int n;
	scanf("%d",&n);
	Heap.heap[0]=(Node)malloc(sizeof(struct node));
	Heap.heap[0]->priority=-1;//�ϵ�ģʽ
	Heap.Numbers=0;

	while(n--) {
		char operation[4];
		getchar();
		scanf("%s",operation);
		switch(operation[0]) {
			case 'P':
				Put();

				break;
			case 'G':
				Get();

				break;
			default:
				break;
		}

	}


	return 0;
}



void Put() {
	Node temp=(Node)malloc(sizeof(struct node));
	scanf("%s%d",temp->Information,&temp->priority);
	int i;
	for(i=++Heap.Numbers; Heap.heap[i/2]->priority>temp->priority; i=i/2) {
		Heap.heap[i]=Heap.heap[i/2];
	}
	Heap.heap[i]=temp;
}
void Get() {
	if(Heap.Numbers<1) {
		printf("EMPTY QUEUE!\n");
		return;
	}
	printf("%s\n",Heap.heap[1]);
	int i;
	for(i=1; i*2<Heap.Numbers;) {
		if(i*2+1<Heap.Numbers&&Heap.heap[i*2+1]->priority<Heap.heap[i*2]->priority) {
			if(Heap.heap[i*2+1]->priority<Heap.heap[Heap.Numbers]->priority) {
				Heap.heap[i]=Heap.heap[i*2+1];
				i=i*2+1;
			} else break;
		} else		if(Heap.heap[i*2]->priority<Heap.heap[Heap.Numbers]->priority) {
			Heap.heap[i]=Heap.heap[i*2];
			i*=2;
		} else break;

	}
	Heap.heap[i]=Heap.heap[Heap.Numbers--];


}
