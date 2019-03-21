//g++  5.4.0
//removing punctuations in string
//!"#$%&'()*+,-./:;?@[\]^_`{|}~ 

#include <iostream>
using namespace std;
void removePunctuations(char a[])
{
    int len=0;
    for(int j=0;a[j]!='\0';j++)
        len++;
    
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='!' || a[i]=='\"' || a[i]== '\'' || a[i]==';' || a[i]=='#' || a[i]=='$' || a[i]=='%' || a[i]=='&' || a[i]=='(' || a[i]==')' || a[i]== '*' || a[i]=='+' || a[i]== ',' || a[i]=='-' || a[i]=='.' || a[i]=='/' || a[i]==':' || a[i]=='\?' || a[i]=='@' || a[i]=='[' || a[i]=='\\' ||  a[i]== ']' || a[i]=='^' || a[i]=='_' || a[i]=='`' || a[i]=='{' || a[i]=='|' || a[i]=='}' || a[i] == '~')
        {
            
            if(a[i+1]!='\0')
            {
                --len;
                for(int k=i+1;k<len;k++)
                {
                    a[k-1]=a[k];  //shift all characters(after punctuation character) to left
                    
                }                 
                i--;  //when you have successive punctuation marks (for eg !, then you dont want to skip check for , therefore you move the checking counter to one index before
            }
        }
    }
    
    a[len-1]='\0';
    
}

//O(N*N) algorithm. make it more efficient.
int main()
{
    char strr[]="Hello!!!, he said ---and went.";
    removePunctuations(strr);
    cout<<strr;
}