//g++  5.4.0
//https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
/*
Find the Rotation Count in Rotated Sorted array
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

Examples:

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after 
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int low, int high) {
    if(high < low) {
        return -1;
    }
    if(high == low) {
        return low;
    }
    int mid = (low+high)/2;
    if(mid > low && arr[mid] < arr[mid-1]) {
        return (mid);
    }
    if(mid < high && arr[mid] > arr[mid+1]) {
        return (mid+1);
    }
    if(arr[mid] < arr[low]) {
        return findPivot(arr, low, mid-1);
    }
    return findPivot(arr, mid+1, high);
}
int main()
{
    int arr[]={15,18,2,3,6,12};
    int n=(sizeof(arr)/sizeof(int));
    
    int idx=findPivot(arr,0,n-1);
    cout<<"\nNumber of rotations = "<<idx;
    return 0;
}
