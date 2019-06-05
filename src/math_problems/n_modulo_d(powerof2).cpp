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
    int dividend=15;
    int num=4;
    
    int ret=0;
    ret=checkpowerof2(num);
    
    if(ret==1)
    {
        int bit_pos= (log(num)/log(2));
        
        if(bit_pos==0)
        {
            cout<<"0";
            return 1;
        }
        int mask=1<<(bit_pos-1);
        
        //mask_of_1s
        int mask_1=(1<<(bit_pos) ) -1;
        cout<<(dividend & mask_1);
    }
    else
    {
        cout<<"error";
    }
    return 1;
}
