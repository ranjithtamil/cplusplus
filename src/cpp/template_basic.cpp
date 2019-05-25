#include <iostream>
using namespace std;

template <typename T>
    T sum(T param1, T param2)
    {
        T retval=param1+param2;
        return retval;
    }

int main()
{
    int val1=5,val2=15;
    cout<<sum(val1,val2)<<endl;
    
    float value1=15.5,value2=10.1;
    cout<<sum(value1,value2)<<endl;
}

