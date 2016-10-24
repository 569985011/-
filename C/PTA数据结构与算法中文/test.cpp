#include<stdio.h>
#include<malloc.h>
#define M 8
#define N 10
typedef int elemtype;
typedef struct{
elemtype *base;
elemtype *top;
int stacksize;
}sqstack;
typedef struct{
    int a,b,dir;
}offsets;
typedef struct{
    int x,y,dr;
}elemstack;
int initstack(sqstack &s)
{
    s.base=(elemtype *)malloc(80 *sizeof(elemtype));
    if(!s.base) return 0;
    s.top=s.base;
    s.stacksize=80;
    return 1;
}
int push(sqstack &s,elemstack &temp)
{
if(s.top-s.base>=s.stacksize)
    {    s.base=(elemtype *)realloc(s.base,(s.stacksize+10)*sizeof(elemtype));
        if(!s.base) return 0;
        s.top=s.base+s.stacksize;
        s.stacksize+=10;
    }
    *s.top=temp;//���Ͳ�ƥ�䣬s.topֻ�ܽ���һ��int��temp��ӵ��3��int�Ľṹ�� 
    s.top++;
    return 1;

}
elemtype pop(sqstack &s,elemstack &temp)
{
    if(s.top==s.base) return 0;
    s.top--;
    *s.top=temp;
    return 1;
}

void path(int maze[M][N],offsets move[4])
{
    elemstack temp;
    sqstack s;
    int g,h,d,i,j;
    int    mark[1][0]=2;//������û�����������Ҫ��ʼ���Ļ������û����Ŵ���������� 
    initstack(s);
    int p=6,q=8;
    temp.x=1;temp.y=1;temp.dr=1;
    push(s,temp);
    while(s.top!=s.base)
    {
        pop(s,temp);
        i=temp.x;j=temp.y;d=temp.dr;
        while(d<=4)
        {
            g=i+move[d].a;h=j+move[d].b;
            if(g==p&&h==q)
            {
                printf("(%d,%d)",p,q);
                while(s.top!=s.base)
                {
                    pop(s,temp);
                    printf("(%d,%d)",temp.x,temp.y);
                }
            }
            if(!maze[g][h]&&!mark[g][h])
            {
                mark[g][h]=2;
                temp.x=i;temp.y=j;temp.dr=d;
                push(s,temp);
                i=g;j=h;d=1;
            }
            else d++;

        }
    }   
printf("no path in maze!");
}


int main()
{
    int maze[M][N]={
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
/*    int i,j;
    for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
        {
            printf("%d  ",a[i][j]);
        }
    printf("\n");
    }
*/
    offsets move[4]={{1,0,1},{0,1,2},{-1,0,3},{0,-1,4}};//ÿ�� �ڵ���Ϣ֮��Ҳ��Ҫ�ö��Ÿ��� 
     path(maze, move);//ȥ�������ţ�ֱ�Ӱ��������ƴ��뼴�� 
/*    int i,j;
    for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
        {
            printf("%d  ",a[i][j]);
        }
    printf("\n");
    }
*/


    return 0;
} 
