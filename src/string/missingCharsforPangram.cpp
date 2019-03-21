
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
  

void missingCharsForPangram(char a[],vector<char> &b)
{
    map<int,int> chrmap;
    chrmap.clear();	//Very important too.
    b.clear();		//Very Important to clear Vector. Else you get inconsistent output.
    for(int i=0;a[i]!='\0';i++)
    {
        //Map's Key is index w.r.t. Capital A (Between 0 to 25)
        if(a[i]>='A' && a[i]<='Z')
        {
            chrmap[a[i]-'A']=1;
        }
        
        //Map's Key is index w.r.t. Capital a (Between 0 to 25)
        if(a[i]>='a' && a[i]<='z')
        {
            chrmap[a[i]-'a']=1;
        }
        
        
    }
    
    for(int c=0;c<=25;c++)
    {
        if(chrmap.count(c)==0)
        {
            b.push_back(c+'a');
        }
         
    }
   // for(int i=0;i<b.size();i++)
     //   cout<<b[i];
}
  
// Driver function 
int main() 
{ 
    char s1[100] = "The quick brown fox jumps over the lazy dog"; 
    char s2[100] = "The quick brown fox jumps over the dog"; 
    vector<char>missing(26);
    missingCharsForPangram(s2,missing);
    
    for(int i=0;i<missing.size();i++)
        cout<<missing[i];
    
    return 0; 
} 