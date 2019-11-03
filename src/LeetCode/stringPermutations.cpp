//g++  5.4.0
//Permutations of String
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Example 
"abc" : 
1.) prefix="a", suffix = "bc"
    1.1 ) prefix = "ab", suffix = "c"
        1.1.1 ) prefix = "abc", suffix = ""
    1.2 ) prefix = "ac", suffix = "b"
        1.2.1 ) prefix = "acb", suffix = ""
    
2.) prefix="b", suffix = "ac"
    2.1 ) prefix = "ba", suffix = "c"
        2.1.1 ) prefix = "bac", suffix = ""
    2.2 ) prefix = "bc", suffix = "a"
        2.2.1 ) prefix = "bca", suffix = ""

3.) prefix="c", suffix = "ab"
    3.1 ) prefix = "ca", suffix = "b"
        3.1.1 ) prefix = "cab", suffix = ""
    3.2 ) prefix = "cb", suffix = "a"
        3.2.1 ) prefix = "cba", suffix = ""
        
Stop whenever suffix == "", and add corresponding prefix to ' vector<string> result '.
*/


void permutations(string prefix, string suffix, vector<string> &res) { //very important to do &res, otherwise ret by val will leave final res to be empty
    int n=suffix.size();
    if(n==0 ) {
        //cout<<"prefix = "<<prefix<<"\n";
        res.push_back(prefix);
    }
    else {
        for(int i=0; i<n; i++) {
            permutations( prefix + suffix.at(i), suffix.substr(0,i) + suffix.substr(i+1,n), res); 
        }
    }
}

vector<string> findPermutations(string s) {
    string prefix="";
    string suffix=s;
    vector<string> res;
    permutations(prefix,suffix,res);
    
    return res;
}
int main()
{
    string s="abc";
    vector<string> result;
    result = findPermutations(s);
    cout<<"\n\n";
    for(int i=0;   i<result.size()   ;i++) {
        cout<<result[i]<<" ";
    }
    cout<<"\n\n";
    return 0;
}
