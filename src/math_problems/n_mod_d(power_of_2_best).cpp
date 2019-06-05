//g++  5.4.0
// https://www.geeksforgeeks.org/compute-modulus-division-by-a-power-of-2-number/
//Compute n modulo d without division(/) and modulo(%) operators, where d is a power of 2 number.
#include <iostream>
#include <math.h>
using namespace std;
int checkpowerof2(int num)
{
    if(num==0)
        return 0;
    
    
    if((num & num-1)!=0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int dividend=1;
    int num=2;
    
    int ret=0;
    ret=checkpowerof2(num);
    
    if(ret==1)
    {
              
        int mask=num -1;
        cout<<(dividend & mask);
        
    }
    else
    {
        cout<<"error";
    }
    return 1;
}
