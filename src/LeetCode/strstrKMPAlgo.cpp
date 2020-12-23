/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void computeLpsArray(string t, vector<int>& lpsArray) {
    lpsArray[0]=0;
    int n=t.size();
    int i=1;
    int j=0;
    
    while(i<n) {
        if(t[i]==t[j]) {
            lpsArray[i]=j+1;
            i++;
            j++;
        }
        else {
            if(j>0) {
                j=lpsArray[j-1];
            }
            else if(j==0) {
                lpsArray[i]=0;
                i++;
            }
        }
        
    }
    
}
bool strstrs(string S, string t, int &start, int &end) {
    //handle edge cases. t.size()==0
    
    int n1=S.size();
    int n2=t.size();
    
    vector<int> lpsArray(n2,0);
    computeLpsArray(t,lpsArray);
    
    int p=0;        //iterator for string S 
    int q=0;        //iterator for string t 
    
    while(p<n1) {
        if(S[p]==t[q]) {
        while(S[p]==t[q]) {
            p++;
            q++;
            if(q==n2) {
                start=((p-1) - n2) +1;
                end=(p-1);
                return true;
            }
        }
        }
        else {
            if(q>0) {
                q=lpsArray[q-1];
            }
            else if(q==0) {
                p++;
            }
        }
        
    }
    return false;
}
int main()
{
    string a= "abxabcabcaby";
    string b= "abcaby";
    
    bool isSubstring=false;
    int start=-1;
    int end=-1;
    isSubstring=strstrs(a,b,start,end);
    
    if(isSubstring==true && start!=-1 && end!=-1) {
        cout<<"\nYes, it is a substring. Start = "<<start<<" End = "<<end;
    }
    
    return 0;
}
