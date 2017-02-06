#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int A,B;
    cout<<"请输入两个整数并回车，本程序将会打印出这两个整数所指定范围内的所有整数"<<endl;
    cin>>A>>B;
    while(A>B){
        cout<<A--<<"_";
    }

    while(A<B){
        cout<<A++<<"_";
    }

    cout<<B<<endl;

    return 0;
}
