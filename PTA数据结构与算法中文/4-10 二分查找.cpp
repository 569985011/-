#include <stdio.h>
#include <stdlib.h>
/*������
ʱ��	���	�÷�	��Ŀ	������	��ʱ��ms��	�ڴ棨MB��	�û�
2016-02-09 19:45	����ȷ	20	4-10	gcc	34	1	569985011
���Ե���
���Ե�	���	�÷�/����	��ʱ��ms��	�ڴ棨MB��
���Ե�1	����ȷ	10/10		2		1
���Ե�2	����ȷ	2/2			14		1
���Ե�3	����ȷ	1/1			1		1
���Ե�4	����ȷ	1/1			1		1
���Ե�5	����ȷ	2/2			11		1
���Ե�6	����ȷ	2/2			34		1
���Ե�7	����ȷ	2/2			16		1
*/
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput() /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
{int n;
scanf("%d",&n);
List Tbl=(List)malloc(sizeof(struct LNode));
//printf("%d\n",sizeof(LNode));//��֤��������ռ�Ҳ��һ���������ˣ��������� 
for(int i=1;i<n+1;i++){
	scanf("%d",&Tbl->Data[i]);
}
Tbl->Last=n;
return Tbl;
}
Position BinarySearch( List Tbl, ElementType K );

int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( List Tbl, ElementType K ){
	if(Tbl->Last>MAXSIZE)Tbl->Last=MAXSIZE-1;
	int left=1,right=Tbl->Last;//Last->ʵ�ʵ�ַ 
	
	while(left<=right){//
		int mid=(left+right)/2;
		if(Tbl->Data[mid]==K)return mid;
		if(Tbl->Data[mid]>K)right=mid-1;
		else left=mid+1;
		
	}
	return NotFound;
}
