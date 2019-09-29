#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 12;
    int m = 1;
    while( n & m ) {
        n = n ^ m;
        m = m<<1;
    }
    n = n ^ m;
    cout << n;
    return 0;   
}

//To add 1 to a number x (say 0011000111), flip all the bits after the rightmost 0 bit (we get 0011000000).
//Finally, flip the rightmost 0 bit also (we get 0011001000) to get the answer.
