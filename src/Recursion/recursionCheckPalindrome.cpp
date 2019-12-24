//g++  5.4.0
//checkPalindromeRecursive
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string str, int low, int high) {
    if(low>high) {
        return false;
    }
    if(low==high) {
        return true;
    }
    if(str[low]!=str[high]) {
        return false;
    }
    
        return checkPalindrome(str,low+1,high-1);
    
}
int main()
{
    string str="WOTOWW";
    int n=str.size();
    bool result=checkPalindrome(str,0, n-1);
    cout<<result;
    return 0;
}
