#include <stdio.h>

#ifndef __STACK_CX16_H__
#define __STACK_CX16_H__

#include <stdlib.h>

typedef struct stack_CX16 {
	void* Base;
	struct stack_CX16* Next;
}* STACK;

void creat(STACK*This) {
	*This=NULL;
}
bool push(STACK*This,void*Base) {
	STACK temp=(STACK)malloc(sizeof(struct stack_CX16));
	temp->Base=Base;
	temp->Next=*This;
	*This=temp;
}
void* pop(STACK*This) {
	void*temp=NULL;
	if(*This) {
		temp=(*This)->Base;
		*This=(*This)->Next;
	}
	return temp;
}
int size(STACK*This) {
	int num=0;
	for(STACK temp=*This; temp; temp=temp->Next,++num);
	return num;
}
#endif



