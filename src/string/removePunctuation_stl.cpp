//g++  5.4.0
//removing punctuations in string
//!"#$%&'()*+,-./:;?@[\]^_`{|}~ 

#include <iostream>
using namespace std;
void removePunctuations(string &a)
{
    int len=a.size();
    for(int i=0;i<len;i++)
    {
        
    if(ispunct(a[i]))
    {
        a.erase(i--,1);
        len=a.size();   //updating length of new string
    }
        
    }
    
    
    
}


int main()
{
    string strr="Hello!!!, he said ---and went.";
    removePunctuations(strr);
    cout<<strr;
}