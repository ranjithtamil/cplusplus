//g++  5.4.0
// SelectionSort
#include <iostream>
using namespace std;
void insertionSort(int arr[],int n) {
    for(int i=1; i<n; i++) { 
        int j=i-1;
        int temp = arr[i];
        while(j>=0) {
            if(arr[j] > temp) {
                arr[j+1]=arr[j];
            j--;    
            }
            else {
                break;}
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int arr[10]={3,2,5,6,2,1,10,12,-1,0};
    insertionSort(arr,sizeof(arr)/sizeof(int));
    
    for(int i = 0; i<(sizeof(arr)/sizeof(int));i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
 //   std::cout << "Hello, world!\n";
}
