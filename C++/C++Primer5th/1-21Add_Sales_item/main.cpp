#include <iostream>
#include"Sales_item.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"����������ISBN��ͬ���鼮������Ϣ"<<endl;
    Sales_item Book1,Book2;
    cin>>Book1>>Book2;

    cout << Book1+Book2 << endl;
    return 0;
}
