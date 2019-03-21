
#include <iostream>
using namespace std;
int isSorted(int a[],int index)
{
    if(index==0)
        return 1;
    else
    {
        if(a[index]>a[index-1])
        {
           return isSorted(a,index-1);
        }
        else
        {
            return 0;
        }
    }
                  
}
int main()
{
    //std::cout << "Hello, world!\n";
    int arr[]={-1,0,2,4,5,6,7,8,9,10};
    int ret=0,idx=(sizeof(arr)/sizeof(int))-1;
    
    ret=isSorted(arr,idx);
    
    cout<<"\ninSortedOrder = "<<ret;
    return 0;
}