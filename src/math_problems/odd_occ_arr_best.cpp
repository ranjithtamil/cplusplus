//g++  5.4.0
/*
https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
*/
//Find Number occuring odd number of times
#include <iostream>
using namespace std;
#include<map>
#include<bits/stdc++.h>
#include<algorithm>
int find_odd(int *arr,int arr_size);

int find_odd(int *arr,int arr_size)
{
    int res=0;
    for(int i=0;i<arr_size;i++)
    {
        res=res^(arr[i]);
    }
    
    return res;
}
int main()
{
    int arr[]={1,2,3,2,3,1,3};
    int arr_size=(sizeof(arr)/sizeof(int));
    int res=find_odd(arr,arr_size);
    cout<<res<<endl;

}
