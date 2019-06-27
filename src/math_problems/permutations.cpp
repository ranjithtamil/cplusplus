//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generate_perms(vector<int> &perm,int n);

void generate_perms(vector<int> &perm,int n)
{
    
    if(perm.size() == n)
    {
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            
            cout<<perm[i]<<" ";
        }
    }
    int k;
    
    for(k=0;k<n;k++)
    {
        if(find(perm.begin(),perm.end(),k)==perm.end())
        {
            perm.push_back(k);
            generate_perms(perm,n);
            perm.pop_back();
        }
    }
}
int main()
{
    vector<int> vecNums={};
    generate_perms(vecNums,4);
    std::cout << "Hello, world!\n";
}
