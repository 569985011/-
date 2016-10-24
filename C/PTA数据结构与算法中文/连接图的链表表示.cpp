#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*

*/
typedef int ElementType;
typedef int ValueType;
typedef struct VNode *VTree; 
struct Ninfo{
	ValueType  Weight;//��¼Ȩֵ�����Ǳ��룬
	VTree NodeAddress;// ָ��Ŀ���ַ 
};
struct VNode{
	ElementType Data;//��������� 
	Ninfo* NodeArray;//ָ�����飬ָ���������ӵĽ�㣻
	 
	int MaxSize;//���ָ������ʹ�ã���¼���� 
	VTree Next;//��ʽ�洢�����ڲ���ɾ���� 
};

VTree FindX(VTree V,EmentType X);
VTree BuildN(VTree V,EmentType Data);
VTree InsertN(VTree V,int X,Ninfo* Info);

int main(){




return 0;
}
VTree FindX(VTree V,EmentType X){
	while(V){
		if(V->Data==X)return V;
		V=V->Next;
	}return NULL;
}
VTree BuildN(VTree V,EmentType Data){
	if(FindX(V,Data)!=NULL){
		printf("�ڵ��Ѵ��ڣ������ؽ�");return V; 
	}
	VTree NewV=(VTree)malloc(sizeof(struct VNode));	
	NewV->Data=Data;
	NewV->MaxSize=0;
	NewV->Next=NULL;
	if(!V)return NewV;
	while(V->Next)V=V->Next;
	V->Next=NewV;
	return V; 
}

VTree InsertN(VTree V,int X,Ninfo* Info){
	VTree N=FindX(V,X);
	if(!N)N=BuildN(V,X); 
	Ninfo*NewA=(Ninfo*)malloc(sizeof(struct Ninfo)*(N->MaxSize+1));
	for(int i=0;i<N->MaxSize;i++){
		NewA[i]=N->NodeArray[i];
	}	Ninfo*temp=N->NodeArray;
	N->NodeArray=NewA;free(temp);
	N->NodeArray[++N->MaxSize]=Info;
} 
