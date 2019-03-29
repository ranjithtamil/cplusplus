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
        
        while(t[i+j]==p[j])           //i will be starting position where first character of t and p matches.    From here, only j keeps incrementing
        {
            j++;
          
            
        if(j==m)
        {
            cout<<" Position is "<<i;
            return 0;
        }
        }
           
        

    }
    
    cout<<"\nSubstring Not Found ";
    return 0;
}
