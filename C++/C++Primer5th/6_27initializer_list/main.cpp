#include <iostream>
#include<initializer_list>

using namespace std;

auto Sum(initializer_list<int> k){
    int sum=0;
    for(auto i:k)sum+=i;
    return sum;
}

int main(int argc, char *argv[])
{

    cout << Sum({1,2,3,4,5}) << endl;
    return 0;
}
