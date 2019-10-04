//g++  5.4.0
// SelectionSort
#include <iostream>
using namespace std;

void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int min_index = i;
        for(int j=i+1;j<n;j++) {
            if( arr[j] < arr[min_index] ) {
                min_index = j;
            }
        }
        swapp( &(arr[min_index]), &(arr[i]));
    }
}
int main()
{
    int arr[10]={3,2,5,6,2,1,10,12,-1,0};
    selectionSort(arr,sizeof(arr)/sizeof(int));
    
    for(int i = 0; i<(sizeof(arr)/sizeof(int));i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
 //   std::cout << "Hello, world!\n";
}
