#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int A,B;
    cout<<"�����������������س��������򽫻��ӡ��������������ָ����Χ�ڵ���������"<<endl;
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
