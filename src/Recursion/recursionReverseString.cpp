#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void reverse(string str, int n) {
    if(n==0) {
        return;
    }
    cout<<str.at(n-1);
    reverse(str,n-1);
}
int main()
{
    string str="HelloWorld";
    int n=(str.size());
    reverse(str,n);
    return 0;
}
