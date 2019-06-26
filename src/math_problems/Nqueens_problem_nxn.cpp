//g++  5.4.0
//Consider the input array to be like this....
/*
a[0]=2  ----> which means position is 0,2
a[1]=0  ----> which means position is 1,0
a[2]=3  ----> which means position is 2,3
a[3]=1  ----> which means position is 3,1
-------------------------------------
|                                   |
|                  Q                |
-------------------------------------
|                                   |
|  Q                                |
-------------------------------------
|                                   |
|                          Q        |
-------------------------------------
|          Q                        |
|                                   |
-------------------------------------
*/
#include <iostream>
using namespace std;
int abso(int val)
{
    if(val<0)
    {
        return (-1*val);
    }
    else
    {
        return val;
    }
}
int main()
{
    int flag=0;
    int a[]={2,0,3,1};
    
    int x1,x2,y1,y2;
    for(int i=0;i<4;i++)
    {
        x1=i;
        y1=a[i];
        for(int j=i+1;j<4;j++)
        {
            x2=j;
            y2=a[j];
            
            if(abso(x1-x2)==abso(y1-y2))
            {
                flag=-1;
            }
            
        }
        
    }
    if(flag==0)
    {
        cout<<"correct solution";
    }
    else
    {
        cout<<"incorrect solution";
    }
}
