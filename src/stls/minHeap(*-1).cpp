// C++ Progrma to implement min heap
// using default priority_queue(max-heap)
 
#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
    // data
    int arr[] = { 25, 7, 9, 15, 20, 36, 50 };
   
      // default priority_queue using max-heap
    priority_queue<int> pq;
   
      // size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // multiply -1 with all elements while
    // inserting
    for (int i = 0; i < n; i++) {
        pq.push((-1) * arr[i]);
    }
 
    // multiply all elements with -1 while
    // retrive the elements
    while (!pq.empty()) {
        cout << (pq.top()) * (-1) << " ";
        pq.pop();
    }
 
    return 0;
}
