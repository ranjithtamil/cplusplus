//g++  5.4.0
// Find subarray with given sum - Efficient
#include <iostream>
using namespace std;
void subarray_sum(int a[], int siz, int sum) {
    if(siz==0){cout<<"Not found";return;}
    
    int n=siz;
    int start=0;
    int curr_sum=a[0];
    for(int i=1;i<=n;i++) {
        while(curr_sum > sum && (start< (i-1)) ) {
            curr_sum=curr_sum - a[start];
            start++;
        }
        if(curr_sum == sum) {
            cout<<"\nSubarray found between indices "<<start<<" and " << i-1;
            return;
        }
        
        if(i<n) {
            curr_sum = curr_sum + a[i];
        }
    }
    cout<<"\nSubarray not found";
    
}
int main()
{
    int a[] = {15, 2, 4, 8, 9, 5, 10, 23};    
    int sum = 23;
    subarray_sum(a,(sizeof(a)/sizeof(int)),sum);
    return 0;
}
