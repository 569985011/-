#include  <stdio.h>
#define STUD 30            //最多可能的学生人数
#define COURSE 5             //最多可能的考试科目数
void  Total(int *score, int sum[], float aver[], int m, int n);
void  Print(int *score, int sum[], float aver[], int m, int n);
int main(void)
{
         int     i, j, m, n, score[STUD][COURSE], sum[STUD];
         float   aver[STUD];
         printf("Enter the total number of students and courses:\n");
         scanf("%d%d",&m,&n);
         printf("Enter score:\n");
         for (i=0; i<m; i++)
         {
            for (j=0; j<n; j++)
            {
                scanf("%d", &score[i][j]);
            }
        }
        Total(*score, sum, aver, m, n);
        Print(*score, sum, aver, m, n);
        return 0;
}

void  Total(int *score, int sum[], float aver[], int m, int n)
{
        int  i, j;
        for (i=0; i<m; i++)
        {
            sum[i] = 0;
            for (j=0; j<n; j++)
            {
                sum[i] = sum[i] + *(score + i * COURSE+ j);
            }
            aver[i] = (float) sum[i] / n;
        }
}

void  Print(int *score, int sum[], float aver[], int m, int n)
{
        int  i, j;
        printf("Result:\n");
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                printf("%4d\t", *(score + i * COURSE + j));
            }
            printf("%5d%\t6.1f\n", sum[i], aver[i]);
     }
}
