//g++  5.4.0
// Find subarray with given sum - Brute Force
#include <iostream>
using namespace std;
void subarray_sum(int a[], int siz, int sum) {
    int n=siz;
    for(int i=0;i<n;i++) {
        int cur_sum = a[i];
        for(int j=i+1;j<=n;j++) {
            if( cur_sum == sum ) {
                cout<<"\n Subarray found : " ;
                cout<<"\n Indices = "<<i<<" to "<<j-1;
                return;
            }
            if( (cur_sum > sum) || j>=n) {
                break;
            }
            cur_sum=cur_sum+a[j];
        }
        
    }
    cout<<"\n SubarrayNOT Found";
}
int main()
{
    int a[] = {15, 2, 4, 8, 9, 5, 10, 23};    
    int sum = 23;
    subarray_sum(a,(sizeof(a)/sizeof(int)),sum);
    return 0;
}
