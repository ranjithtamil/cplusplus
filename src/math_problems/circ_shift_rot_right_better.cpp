//g++  5.4.0

#include <iostream>
#define systemmaxbit 32
using namespace std;

int rotateright(int num,int bitspace,int bitshift);
int rotateright(int num,int bitspace,int bitshift)
{
    bitshift=(bitshift%bitspace);
    if(bitshift==0)
    {
        return num;
    }
    else
    {                
        unsigned int num1=num>>bitshift;
        unsigned int num2=num<<(bitspace - bitshift);
        num2=(num2<<(systemmaxbit - bitspace));
        num2=(num2>>(systemmaxbit - bitspace));  
        num=num1|num2;
        return num;
    }
}

int main()
{
    int num=9;
    int bitspace=4;
    int bitshift=5;
    int result=rotateright(num,bitspace,bitshift); 
    cout<<result;
}
