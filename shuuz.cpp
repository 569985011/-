#include<stdio.h>
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int i,j;
    
    printf("�仯ǰ:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
    
}
