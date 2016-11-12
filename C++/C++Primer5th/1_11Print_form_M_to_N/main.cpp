#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int m,n;
    cout <<"请输入两个整数，指定要输出的整数区间（例：3  4）：";
    cin >>m>>n;
    if(m<n){while(m<=n){cout <<m++ <<"_";}}
    else   {while(m>=n){cout <<m-- <<"_";}}
    cout <<endl;
    return 0;
}
