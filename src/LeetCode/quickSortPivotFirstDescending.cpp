#include <iostream>
using namespace std;
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition(int arr[], int low, int high) {
    int i=high+1;
    int pivot=arr[low];
    for(int j=high;j>=low;j--) {
        if( arr[j] < pivot ) {
            i--;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i-1], &arr[low]);
    return (i-1);
}
void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver Code 
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    //int arr[]={15,1,343,23,100,-1,45,33,112,0};
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
  
