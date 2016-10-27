#include <stdio.h> 
#include <initializer_list>
#include <vector> 
using namespace std;

int main( void )
{
	double sum=0;
	vector<auto> k={1,2,3,4};
    for(auto i:k)sum+=i;
    printf("%lf",sum);
}
