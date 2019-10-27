//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int l,int h,int target) {
    
    int mid=(l+h)/2;
    //cout<<"\nBS : l = "<<l<<" m = "<<mid<<" h = "<<h<<" t = "<<target<<"\n";
    if((target > arr[h]) || (target < arr[l]) ) {
        return -1;
    }
    if(arr[mid]==target) {
        return mid;
    }
    else if(target > arr[mid]) {
        binSearch(arr,mid+1,h,target);
    }
    else {
        binSearch(arr,l,mid,target);
    }
    
}
int main() {
    int arr[]={3,4,5,2,1,9,11,23};
    //1 2 3 4 5 9 11 23
    int n=(sizeof(arr)/sizeof(int));
    sort(arr,arr+n);
    int target=11;
    int pos=-1;
    pos=binSearch(arr,0,n-1,target);
    if(pos==-1) {
        cout<<"\nNot Found";
    }
    else {
        cout<<"\nFound. Position = "<<(pos+1);
    }
    //std::cout << "Hello, world!\n";
}
