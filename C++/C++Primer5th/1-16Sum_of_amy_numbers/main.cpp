#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"求和软件"<<endl;
    int sum=0,val;
    cout<<"请输入一个数（输入非有效整数或“ctrl+z”或“ctrl+d 结束输入并输出sum"<<endl;
    while(cin>>val){
        cout<<"请输入一个数（输入非有效整数或“ctrl+z”或“ctrl+d 结束输入并输出sum"<<endl;
        sum+=val;
    }
    cout <<"The sum is "<< sum << endl;

    return 0;
}
