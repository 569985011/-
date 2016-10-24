#include<iostream>
#include<string>
using namespace std;
int main(){
    string s("some string");//申明一个字符串变量s,并初始化为“some string"
    for (string::size_type ix=0;ix!=s.size();++ix)//给函数size_type定义一个变量ix,并初始化ix=0;当ix等于s的最后一个字符时，跳出循环。
    {
        cout<<s[ix]<<endl;
    }
    for(string::size_type index=0;index!=s.size ();++index){
        cout<<s.at (index)<<endl;
    }
    return 0;
}
