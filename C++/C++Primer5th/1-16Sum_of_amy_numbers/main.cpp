#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"������"<<endl;
    int sum=0,val;
    cout<<"������һ�������������Ч������ctrl+z����ctrl+d �������벢���sum"<<endl;
    while(cin>>val){
        cout<<"������һ�������������Ч������ctrl+z����ctrl+d �������벢���sum"<<endl;
        sum+=val;
    }
    cout <<"The sum is "<< sum << endl;

    return 0;
}
