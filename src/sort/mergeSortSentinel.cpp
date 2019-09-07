#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<< " " << arr[i];
    }
}
void merge(int arr[], int l, int m, int r) {          // Takes Theta(n) time complexity
    int n1 = ( m - l + 1 );
    int n2 = ( r - m );
    int L[n1+1];
    int R[n2+1];
    
    for( int i = 0; i < n1; i++ ) {
        L[i] = arr[l+i];
    }
    L[n1]=INT_MAX;
    for( int j = 0; j < n2; j++ ) {
        R[j] = arr[m+1+j];
    }
    R[n2]=INT_MAX;
    
    int i=0;
    int j=0;
    int k=l;
    
    while(k<=r) {
    if( L[i] < R[j] ) {           // No need to check whether each of the subarrays are empty before populating. 
            arr[k] = L[i];        // If sentinel(max_int)/last element is exposed, array is empty and it cannot be the smaller element
            i++;                  // So other subarray will have elements smaller than it. Once (r-l+1) non-sentinel elements have been
        }                         // sorted, then it doesnt enter this loop. while exiting, i = ( n1+1 ) & j = ( n2+1 )
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
}
void mergeSort( int arr[], int l, int r ) {
    if( l < r ) {
    int m = (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}
int main() {
    //int a[]= {12, 11, 13, 5, 6, 7};
    int a[]={33,22,99,128,0,23,22,89,99};
    int n=(sizeof(a)/sizeof(int));
    mergeSort(a, 0, n-1);
    printArray(a,n);
}
