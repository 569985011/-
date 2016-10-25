#include<stdio.h>
#include<string.h>
struct ge{
    int x,y;
};
struct ge data[120];
struct ge move[4];//方位数组

int main()
{
    //开辟结构数组；
    int mi[55][55],i,j,h,l,x,y;
    int rh,rl,ch,cl,count,Count,num,NUM,point,p;
    char gezi;
    move[0].x=0; move[1].x=1;  move[2].x=0; move[3].x=-1;
    move[0].y=1; move[1].y=0;  move[2].y=-1; move[3].y=0;
    while(scanf("%d%d",&h,&l)!=EOF)
    {
        if(h==0&&l==0)
            break;
        scanf("%d%d%d%d",&rh,&rl,&ch,&cl);
        getchar();
        for(i=1;i<=h+2;i++){
            for(j=1;j<=l+2;j++){
            if(i==1||i==h+2||j==1||j==l+2){
                mi[i][j]=0;
            }
            else{
            if(i>=3&&j==2)
            getchar();
            scanf("%c",&gezi);
            if(gezi=='.')
            mi[i][j]=1;
            else if(gezi=='#')
            mi[i][j]=0;
            }
            }
        }

//下列代码为出口寻找************************
        NUM=1;           //为进入循环而设置前置值
        Count=count=0;
        for(i=0;i<120;i++){
            data[i].x=-1;
            data[i].x=-1;
            }
        data[count].x=rh+2;
        data[count].y=rl+2;
        mi[rh+2][rl+2]=-1;//入口入栈并且赋值为-1
        point=0;       //跳出判断数值
        p=0;            //一个执行判断标准
        if(rh==ch&&rl==cl){
            printf("YES0\n");
            p=1;
        }
       if(p==0){
        while(NUM>0){
        num=0;
            for(j=0;j<NUM;j++){

            for(i=0;i<4;i++){
                x=data[Count-j].x+move[i].x;//当前栈中
                y=data[Count-j].y+move[i].y;
                if(mi[x][y]==1){
                    if(x==ch+2&&y==cl+2){
                    printf("YES1\n");
                    point=1;//寻找到出口结束跳出标志
                    break;}

                    else{
                    mi[x][y]=-1;//将走过的格子赋值为-1,防止重复
                    num+=1;//每个格子有的通路
                    count+=1;
                    data[count].x=x;
                    data[count].y=y;}
                    }
                    }//move

        if(point==1)
            break;
        }
        NUM=num;
        Count=count;

        if(point==1)
            break;
        }
        }
        if(NUM==0&&point==0&&p==0)
            printf("NO\n");



    }//while输入

    return 0;
}
