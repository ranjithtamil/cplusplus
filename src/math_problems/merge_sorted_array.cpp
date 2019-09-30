//g++  5.4.0
// Merge two sorted arrays in sorted order. (Or it could be that first array arr1 is sorted, and array arr2 in unsorted)

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
    
    for(int i=0;i<n1;i++) {
        arr3[i]=arr1[i];
    }

    int array3_end = n1-1;
    for(int i=0;i<n2;i++) {
        int j = array3_end;
        while(arr2[i] < arr3[j]) {
            arr3[j+1]=arr3[j];
            j--;
        }
        arr3[j+1]=arr2[i];
        array3_end++;
    }
    
    for(int k=0;k<n3;k++) {
        cout<<arr3[k]<<" ";
    }
    return 0;
}
