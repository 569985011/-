#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "/*";//双引号先起作用，/*被当做字符串
    cout <<"*/";//同上
//    cout <</* "*/" */;//引号不匹配
//    cout << /* "*/  /*"/*" */;//'<<'右侧没有元素，被两组/**/注释掉了
    return 0;
}
