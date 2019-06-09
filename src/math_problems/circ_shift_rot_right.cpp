
#include <iostream>
using namespace std;

int rotateright(int num,int bitspace,int bitshift);

int rotateright(int num,int bitspace,int bitshift)
{
    
    bitshift=(bitshift%bitspace);
    //cout<<"bitshift="<<bitshift<<endl;
    
    if(bitshift==0)
    {
        return num;
    }
    else
    {
        int mask=(1<<(bitspace-1));
        for(int i=0;i<bitshift;i++)
        {
            if(num%2==1)
            {
                num=num>>1;
                num=(num | mask);
            }
            else
            {
                num=num>>1;
            }
        }
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
    
    //std::cout << "Hello, world!\n";
}
