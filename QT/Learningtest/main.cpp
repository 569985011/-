#include<iostream>
#include<string>
using namespace std;
int main(){
    string s("some string");//����һ���ַ�������s,����ʼ��Ϊ��some string"
    for (string::size_type ix=0;ix!=s.size();++ix)//������size_type����һ������ix,����ʼ��ix=0;��ix����s�����һ���ַ�ʱ������ѭ����
    {
        cout<<s[ix]<<endl;
    }
    for(string::size_type index=0;index!=s.size ();++index){
        cout<<s.at (index)<<endl;
    }
    return 0;
}
