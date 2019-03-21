
#include <bits/stdc++.h> 
using namespace std; 
  

int isPangram(char a[])
{

    map<char,int> chrmap;
    chrmap.clear();
    for(int i=0;a[i]!='\0';i++)
    {
        chrmap[a[i]]=1;
    }
    
    for(char j='a';j<='z';j++)
    {
        if(chrmap.count(j)<=0)
            return 0;
    }
    return 1;
}
  
// Driver function 
int main() 
{ 
    char s1[100] = "The quick brown fox jumps over the lazy dog"; 
    char s2[100] = "The quick brown fox jumps over the dog"; 
    int ret=0;
    ret=isPangram(s2);
    cout<<ret;
    return 0; 
} 