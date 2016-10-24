#include  <stdio.h>
int main()
{ 
  int i, j, sum = 0, n; 
  scanf("%d",&n); 
  for (i=1,j=n; i<=j; i++,j--) 
  {
      sum = sum + i + j;
  }
  if(n%2==1)sum-=((n+1)/2);//这才是这个程序的\
  关键：当n为奇数时我们的运算就多加了一个中间数。需要减去。 
  
  printf("sum = %d", sum);
  return 0;
}
