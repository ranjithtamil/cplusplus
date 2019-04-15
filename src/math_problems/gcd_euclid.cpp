//g++  5.4.0
//GCD OF TWO NUMBERS x&Y. Euclidean Algorithm
#include <iostream>
using namespace std;
int main()
{
    int x=15;
    int y=5;
    
    
    int a;
    int b;
    int r;
    /*
    if(x>y)
    {
        a=x;
        b=y;
    }
    else
    {
        b=x;
        a=y;
    }
    */
    a=x;
    b=y;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
        
    }
    cout<<"\nGCD is "<<a;
    return 0;
    
}
