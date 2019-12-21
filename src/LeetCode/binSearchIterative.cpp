//g++  5.4.0
//Iterative Binary Search
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findElement(int arr[], int low, int high, int ele) {
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==ele) {
            return mid;
        }
        
        if(ele > arr[mid]) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
        
    }
    return -1;
}
int main()
{
    int arr[]={2,3,6,12,15,18};
    int n=(sizeof(arr)/sizeof(int));

    int ele = 15;
    
    int idx=findElement(arr,0,n-1,ele);
    cout<<idx;
    return 0;
}
