//g++  5.4.0

#include <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(int arr[], int len) {
    int swapped;
    do{
        swapped=0;
        for(int i=0; i<len-1; i++) {
            
            if( arr[i] > arr[i+1] ) {
                swap(arr[i],arr[i+1]);
                swapped=1;
            }
        }
    }while(swapped==1);
    for( int i=0; i<len; i++) {
        cout<<" " <<arr[i];
    }
}
int main() {
    int a[]={5,1,4,2,8};
    bubbleSort(a,5);
}
