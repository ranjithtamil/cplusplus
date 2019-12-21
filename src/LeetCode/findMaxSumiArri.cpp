//g++  5.4.0
/*
https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i].
Examples :

Input: arr[] = {1, 20, 2, 10}
Output: 72
We can 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Output: 330
We can 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1,20,2,10};
    //int a[]={10,1,2,3,4,5,6,7,8,9};
    
    int n=sizeof(a)/sizeof(int);
    int arraySum=0;
    int optimVal=0;
    for(int i=0;i<n;i++) {
        arraySum = arraySum + (a[i]); // sumOfArray = a[0] + a[1] + a[2] + ... + a[n-1]
        optimVal = optimVal + (i*a[i]); // optimVal = sumOf i*a[i] = 0*a[0] + 1*a[1] + 2*a[2] + 3*a[3] + ... + (n-1)*a[n-1]
    }
    int maxSum = optimVal;
    
    int prevArraySum = optimVal;
    int rotationNumber = 0;
    for(int i=1;i<=n-1;i++) { //n-1 rotations
        int newArraySum = prevArraySum + (arraySum - (n*a[n-i]));
        if(newArraySum > maxSum) {
            maxSum = newArraySum;
            rotationNumber = i;
        }
        prevArraySum = newArraySum;
    }
    cout<<"MaxSum is "<<maxSum<<" with "<<rotationNumber<<" rotations ";
    return 0;
}
