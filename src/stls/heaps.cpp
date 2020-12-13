
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int>& v) {
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}
int main()
{
    vector<int> v1={20, 30, 40, 25, 15}; 
    make_heap(v1.begin(),v1.end());
    printVector(v1);
    
    v1.push_back(70);
    printVector(v1);
    //order the heap again
    push_heap(v1.begin(),v1.end());
    printVector(v1);
    
    
    //lets print the max element
    cout<<"\nMax element is "<<v1.front()<<"\n";
    //lets extract the max element
    pop_heap(v1.begin(),v1.end());
    printVector(v1);
    //even after pop_heap, the max element is not in the front, but it is pushed to the back.so you need to do a pop_back()
    
    cout<<"\nMax element is at the back in "<<v1.back()<<"\n";
    v1.pop_back();
    printVector(v1);
    
    
    //to check if the container satisfies Heap
    cout<<"\n Is this heap = "<<is_heap(v1.begin(),v1.end())<<"\n";
    
    
    //Heap sort in ascending order
    sort_heap(v1.begin(),v1.end()); 
    printVector(v1);
    
    //to check if the container satisfies Heap
    cout<<"\n Is this heap = "<<is_heap(v1.begin(),v1.end())<<"\n";
    
    // using is_heap_until() to check position  
    // till which container is heap 
    auto it = is_heap_until(v1.begin(), v1.end()); 
    
    // Displaying heap range elements 
    cout << "The heap elements in container are : "; 
    for (vector<int>::iterator it1=v1.begin(); it1!=it; it1++) 
       cout << *it1 << " "; 
    
    return 0;
    
}
