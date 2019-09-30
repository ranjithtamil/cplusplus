//g++  5.4.0
// Merge two sorted arrays in sorted order. 
#include <iostream>
using namespace std;
int main()
{
    int arr1[]={1,3,4,5};
    int arr2[]={2,4,6,8};
    int n1=(sizeof(arr1)/sizeof(int));
    int n2=(sizeof(arr2)/sizeof(int));
    int n3=n1+n2;
    int arr3[n3];
    int i=0;
    int j=0;
    int k=0;
    while( i < n1 && j < n2 ) {
        if(arr1[i] < arr2[j]) {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while( i < n1 ) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    
    while( j < n2 ) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    for(int k=0;k<n3;k++) {
        cout<<arr3[k]<<" ";
    }
    return 0;
}
