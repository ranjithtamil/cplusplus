//Rotate n by d bits
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 8
void left_rotate(int n, int d) {
    int result=(n<<d)&(0xFF);
    int res = n >> (INT_BITS-d);
    int fin_result = result | res;
    cout<<fin_result;
}
void right_rotate(int n, int d) {
    int result = (n>>d);
    int res = (n<<(INT_BITS-d))&(0xFF); 
    int fin_result=result| res;
    cout<<fin_result;
}
int main() {
    int n=0b11100010;
    //int n=226;
    int d=3;
    cout<<"\n";
    left_rotate(n,d);
    cout<<"\n";
    right_rotate(n,d);
    return 0;   
}
