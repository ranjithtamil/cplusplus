// An array consists of all numbers repeated exactly 3 times except one number (which has only one occurrence. find this number

//g++  5.4.0

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int find_single_element(int a[], int siz) {
    //unordered_set<int> s(a,a+siz);
    unordered_set<int> s;
    s.insert(a,a+siz);
    int sum=accumulate(s.begin(),s.end(),0);
    int totsum = accumulate(a,a+siz,0);
    int single_ele = ((3*sum) - (totsum))/2;
    return single_ele;
}

int main() {
    int a[7]={3,2,2,2,3,3,9};
    cout<<find_single_element(a,(sizeof(a)/sizeof(int)));
    return 0;
}

