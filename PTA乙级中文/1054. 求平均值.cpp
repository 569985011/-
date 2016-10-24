#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Node;
struct node {
	float Number;
};

Node scan();

int main() {
	int n;
	scanf("%d",&n);
	int numbers=0;
	float sum=0;
	while(n--) {
		Node temp=scan();
		if(temp) {
			numbers++;
			sum+=temp->Number;
		}
	}
	printf("The average of %d numbers is ",numbers);
	if(numbers)printf("%.2f",sum/numbers);else printf("Undefined");
	


		return 0;
}


Node scan(){
	char temp[400];//尽量大，做一个缓冲区用的
	scanf("%s",temp); 
}
