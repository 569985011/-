#include  <stdio.h>
int main()
{ 
  int i, j, sum = 0, n; 
  scanf("%d",&n); 
  for (i=1,j=n; i<=j; i++,j--) 
  {
      sum = sum + i + j;
  }
  if(n%2==1)sum-=((n+1)/2);//�������������\
  �ؼ�����nΪ����ʱ���ǵ�����Ͷ����һ���м�������Ҫ��ȥ�� 
  
  printf("sum = %d", sum);
  return 0;
}
