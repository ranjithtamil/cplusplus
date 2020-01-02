//Print all substrings of a string
#include <iostream>
//#include <string>
#include<bits/stdc++.h>
using namespace std;

/*
void perms(string str) {
    int n=str.size();
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            for(int k=i;k<=j;k++) {
                cout<<str[k];
            }
            cout<<"\n";
        }
       
    }
}
*/
void perms(string str) {
    int n=str.size();
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            cout<<str.substr(i,j-i+1);
            cout<<"\n";
        }
       
    }
}

int main()
{
    string str="abcd";
    perms(str);
    return 0;
}
