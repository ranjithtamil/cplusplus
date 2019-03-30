//g++  5.4.0
//GCD OF TWO NUMBERS x&Y. Euclidean Algorithm-recursive
#include <iostream>
using namespace std;
int gcd_calc(int a,int b)
{
    if(b==0)
        return a;
    else
    {
        gcd_calc(b,(a%b));
    }
}

int main()
{
    int x=15;
    int y=5;
    int a,b;
    int ret;
    
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
    
    ret=gcd_calc(a,b);
    
    
    cout<<"\nGCD is "<<ret;
    return 0;
    
}
