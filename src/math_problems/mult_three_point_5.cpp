//https://www.geeksforgeeks.org/multiply-an-integer-with-3-5/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int x = 12;
    int two_x = x<<1;
    int point_five_x = x>>1;
    cout<<"\n2x = " << two_x;
    cout<<"\n0.5x = " << point_five_x;
    
    int three_point_five_x = x + two_x + point_five_x;
    cout<<"\n3.5x = "<<three_point_five_x;
    return 0;   
}
