#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int m,n;
    cout <<"����������������ָ��Ҫ������������䣨����3  4����";
    cin >>m>>n;
    if(m<n){while(m<=n){cout <<m++ <<"_";}}
    else   {while(m>=n){cout <<m-- <<"_";}}
    cout <<endl;
    return 0;
}
