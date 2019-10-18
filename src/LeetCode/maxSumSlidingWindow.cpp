//g++  5.4.0
/* 
Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum possible for ‘k’ consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700
*/

#include <iostream>
using namespace std;
int main()
{
    int arr[]={400,300,100,400};
    int k=2;
    int win_sum=0,max_sum=0;
    int n=4;
    for( int i=0;(i<k) && (i<n); i++ ) {
        win_sum = win_sum + arr[i];
    }
    max_sum = win_sum;
    for( int j=k;j<n;j++) {
        win_sum = win_sum + arr[j] - arr[j-k];
        max_sum = max(max_sum, win_sum);
    }
    cout<<"Maxsum = "<<max_sum;
    return 0;
}
