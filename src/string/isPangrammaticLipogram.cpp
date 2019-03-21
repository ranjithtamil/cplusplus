
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
//Check for pangrammatic lipogram
//If only one letter in alphabets (A-Z) is missing, then its called a pangrammatic lipogram.
//If multiple letters of alphabet are missing, then its called just a lipogram.
  

int isPangrammaticLipogram(char a[])
{
    map<int,int> chrmap;
    int count_of_missing_characters=0;
    chrmap.clear();
    
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
            count_of_missing_characters++;
        }
         
    }
    if(count_of_missing_characters==1)
    {
        // isPangrammaticLipogram because only one missing character from alphabets
        return 1;
    }
    //if count_of_missing_characters=0->pangram, if count_of_missing_characters=1->pangrammatic lipogram
    //if count_of_missing_characters>1 --> just a lipogram
    return 0;
}
  
// Driver function 
int main() 
{ 
    char s1[100] = "The quick brown fox jumps over the lazy dog"; //Pangram - all alphabets present. none missing
    char s2[100] = "The quick brown fox jumps over the dog"; //Lipogram - missing a,l,y,z
    char s3[100] = "The quick brown fox jumped over the lazy dog"; //Pangrammatic Lipogram - missing s 
    
    int ret;
    ret=isPangrammaticLipogram(s3);
    cout<<ret;
    return 0; 
} 