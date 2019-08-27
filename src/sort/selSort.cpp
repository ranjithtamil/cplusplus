//g++  5.4.0

#include <iostream>
#include <algorithm>
using namespace std;
void selSort(int arr[], int len) {
    for(int i=0; i<len-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<len; j++) {
            if( arr[j] < arr[min_idx] ) {
                min_idx = j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    
    cout<<"\nArray is : \n";
    for( int i=0; i<len; i++) {
        cout<<" " <<arr[i];
    }
}
int main()
{
    int a[]={64,25,12,22,11};
    selSort(a,5);
    //std::cout << "Hello, world!\n";
}
