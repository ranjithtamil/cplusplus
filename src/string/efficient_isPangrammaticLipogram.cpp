
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
//Check for pangrammatic lipogram
//If only one letter in alphabets (A-Z) is missing, then its called a pangrammatic lipogram.
//If multiple letters of alphabet are missing, then its called just a lipogram.
  

int isPangrammaticLipogram(char a[])
{
    map<char,int> chrmap;
    chrmap.clear();

    chrmap['a']=0;
    chrmap['b']=0;
    chrmap['c']=0;
    chrmap['d']=0;
    chrmap['e']=0;
    chrmap['f']=0;
    chrmap['g']=0;
    chrmap['h']=0;
    chrmap['i']=0;
    chrmap['j']=0;
    chrmap['k']=0;
    chrmap['l']=0;
    chrmap['m']=0;
    chrmap['n']=0;
    chrmap['o']=0;
    chrmap['p']=0;
    chrmap['q']=0;
    chrmap['r']=0;
    chrmap['s']=0;
    chrmap['t']=0;
    chrmap['u']=0;
    chrmap['v']=0;
    chrmap['w']=0;
    chrmap['x']=0;
    chrmap['y']=0;
    chrmap['z']=0;
    
    
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            a[i]=a[i]+32;
        
        chrmap[a[i]]=chrmap[a[i]]+1;
        
    }
    
    vector<int> list_of_counts(26);
    list_of_counts.clear();
    for(map<char,int>::iterator it=chrmap.begin();it!=chrmap.end();++it)
    {
        list_of_counts.push_back(it->second); // copy values of chrmap to a vector
    }
    
    //If list_of_counts has only one count of element 0, then its a pangrammatic lipogram
    //If list_of_counts has zero counts of element 0, then its a pangram.
    //If list_of_counts has more than 1 count of element 0, then its just a lipogram.
    
    if(count(list_of_counts.begin(),list_of_counts.end(),0)==1)
        return 1; //Pangrammatic lipogram
    
    else if(count(list_of_counts.begin(),list_of_counts.end(),0)==0)
        return 0; //Pangram
        
    else
        return 0; //Just Lipogram
    
    
        //This algorithm is of O(N) complexity, but uses extra memory for list_of_counts vector
}
  
// Driver function 
int main() 
{ 
    //char s1[100] = "The quick brown fox jumps over the lazy dog"; //Pangram - all alphabets present. none missing
    //char s2[100] = "The quick brown fox jumps over the dog"; //Lipogram - missing a,l,y,z
    char s3[100] = "The quick brown fox jumped over the lazy dog"; //Pangrammatic Lipogram - missing s 
    
    int ret;
    ret=isPangrammaticLipogram(s3);
    cout<<ret;
    return 0; 
} 