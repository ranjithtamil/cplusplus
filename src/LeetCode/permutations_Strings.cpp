//g++  5.4.0
//Generate strings permutations
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(char* a, char* b) {
    char t=*a;
    *a=*b;
    *b=t;
}
void generateStrings(string str, int begin, int n, vector<string>&results) {
    if(begin==n) {    
        results.push_back(str);
    }
    
    for(int i=begin;i<n;i++) {
        swap(&str[i],&str[begin]);
        generateStrings(str,begin+1,n,results);
        swap(&str[i],&str[begin]);
    }
}
int main()
{
    string str="boat";
    int n=str.size();
    vector<string>results;
    generateStrings(str,0,n,results);
    
    for(int i=0;i<results.size();i++) {
        cout<<results[i];
        cout<<"\n";
    }
    return 0;
}
