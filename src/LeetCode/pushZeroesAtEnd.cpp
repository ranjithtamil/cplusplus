//g++  5.4.0

#include <iostream>
using namespace std;
void moveZeroes(int arr[], int n) {
    int nonZeroCnt=0;
    for(int i=0;i<n;i++) {
        if(arr[i]!=0) {
            arr[nonZeroCnt]=arr[i];
            nonZeroCnt++;
        }
    }
    
    for(int i=nonZeroCnt;i<n;i++) {
        arr[i]=0;
    }
}
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={1,2,0,4,3,0,5,0};
    int n=sizeof(arr)/sizeof(int);
    moveZeroes(arr,n);
    printArray(arr,n);
    return 0;
}
