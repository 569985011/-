#include <iostream>
#include"Sales_item.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"请输入两个ISBN相同的书籍销售信息"<<endl;
    Sales_item Book1,Book2;
    cin>>Book1>>Book2;

    cout << Book1+Book2 << endl;
    return 0;
}
