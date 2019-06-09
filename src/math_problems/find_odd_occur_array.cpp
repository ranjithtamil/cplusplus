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
    unordered_map<int,int> occ_map;
    
    for(int i=0;i<arr_size;i++)
    {
        occ_map[arr[i]]++;
    }
    /*
    for(auto j: occ_map)
    {
        if(j.second % 2 !=0)
        {
            return j.first;
        }
    }*/
    
    for(std::unordered_map<int,int>::iterator j=occ_map.begin();j!=occ_map.end();j++)
    {
        if(j->second % 2 !=0 )
        {
            return j->first;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,2,3,1,3};
    int arr_size=(sizeof(arr)/sizeof(int));
    int res=find_odd(arr,arr_size);
    cout<<res<<endl;

}
