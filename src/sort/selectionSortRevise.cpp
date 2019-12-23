//g++  5.4.0
//Selection Sort
#include <iostream>
using namespace std;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={11, 25, 12, 22, 64};
    int i=0,j=0;
    int n=(sizeof(arr)/sizeof(int));
    
    for(int i=0;i<n-1;i++) {
        int minidx=i;
        int flag=0;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minidx]) {
                flag=1;
                minidx=j;
            }
        }
        if(flag==1) {
            swap(arr[i],arr[minidx]);
        }
    }
    printArray(arr,n);
    return 0;
}





































/*
//g++  5.4.0
//Selection Sort
#include <iostream>
using namespace std;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={11, 25, 12, 22, 64};
    int i=0,j=0;
    int n=(sizeof(arr)/sizeof(int));
    for(int i=0;i<n-1;i++) {
        //int min=arr[i];
        int minidx=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minidx]) { //if(arr[j] < min) {
                //min=arr[j];
                minidx=j;
            }
        }
        //int temp=arr[i];
        //arr[i]=arr[minidx];
        //arr[minidx]=temp;
        swap(&arr[i],&arr[minidx]);
    }
    printArray(arr,n);
    return 0;
}
*/
