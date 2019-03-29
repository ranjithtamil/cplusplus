//g++  5.4.0

#include <iostream>
#include <string>
using namespace std;

int main()
{   
    string t="this is a long string but this is the substring";
    string p="this is the substring";
    
    int n=t.length();
    int m=p.length();
    
    for(int i=0;i<=(n-m);i++)
    {
        int j=0;
        
       
        if(t[i]!=p[j])
        {
            
            continue;
        }
        else
        {
            
            int start=i;
                i++;   //To start checking first string from second index, i.e., t[1]
                
          for(j=1;j<=m-1;j++)  //To start checking second string from second index, i.e., p[1]
          {
              if(t[i]!=p[j])
              {
                
                  break;
              }
              else
              {
                
                  i++;
              }
          }
            
            if(j==m)
            {
                cout<<"\nI value is "<<start;
                return 0;
            }
            
        }
    }
    
    cout<<"\nSubstring Not Found";
    return 0;
}
