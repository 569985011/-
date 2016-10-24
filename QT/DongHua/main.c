#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

int main() {
    HANDLE H_stdout;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD rec;
    int i;
    H_stdout = GetStdHandle( STD_OUTPUT_HANDLE );
    rec.X = 160; rec.Y=65;   // 宽500个字，高100个字
    SetConsoleScreenBufferSize(H_stdout, rec);
    GetConsoleScreenBufferInfo( H_stdout, &csbi );  // 获取屏幕设置信息
//    printf("w=%d h=%d\n",csbi.dwSize.X,csbi.dwSize.Y);  //打印当前宽高


    FILE*filename=fopen("E:\\QT\\DongHua\\badapple.txt","r");

    if(filename) {
        while(!feof(filename)){
            char temp[1024];
            while(fgets(temp,351,filename)&&strlen(temp)>6)
                printf("%s",temp);
            printf("%s",temp);
            auto b=clock();
                for(auto i=0;i<1;) { //完成1/30秒定时
                i=clock()-b;
                i/=CLOCKS_PER_SEC/10;
            }
                    system("cls");
        }
        fclose(filename);
    } else printf("ERROR!\n");


    return 0;
}
