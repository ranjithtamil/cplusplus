
//HeapSort ascending with MaxHeap modules
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MaxHeap {
public:
vector<int> heaparr;
int capacity;
int heapsize;
MaxHeap(vector<int> arr, int cap) {
    capacity = cap;
    heapsize = arr.size();
    heaparr = arr;
    buildHeapFromArray();
}
MaxHeap(int size) {
    capacity = size;
    heapsize = 0;
}
void heapifyDown(int index) {
    int largest = index;
    if(hasLeft(index)) {
    if(hasLeft(index) && heaparr[left(index)]>heaparr[largest]) {
        largest = left(index);
    }
    if(hasRight(index) && heaparr[right(index)]>heaparr[largest]) {
        largest = right(index);
    }
    if(largest!=index) {
        swap(heaparr[index],heaparr[largest]);
        heapifyDown(largest);
    }
    }
}
void buildHeapFromArray() {
    int lastNonLeafNode = (heapsize/2 - 1);
    for(int i=lastNonLeafNode;i>=0;i--) {
        heapifyDown(i);
    }
}
bool hasParent(int i) {
    if((i-1)/2 >= 0) {
        return true;
    }
    return false;
}
bool hasLeft(int i) {
    if(2*i + 1 < heapsize) {
        return true;
    }
    return false;
}
bool hasRight(int i) {
    if(2*i + 2 < heapsize) {
        return true;
    }
    return false;
}
int left(int i) {
    return (2*i +1);
}
int right(int i) {
    return (2*i +2);
}
int parent(int i) {
    return (i-1)/2;
}
void swap(int&x, int&y) {
    int temp=x;
    x=y;
    y=temp;
}
void printHeap() {
    for(int i=0;i<heapsize;i++) {
        cout<<" " <<heaparr[i];
    }
}
/********/
void insertKey(int key) {
    if(heapsize==capacity) {
        cout<<"\nOverFlow";
        return;
    }
    heaparr.push_back(key);
    heapsize++;
    
    int index = heapsize-1;
    while(hasParent(index) && heaparr[index] > heaparr[parent(index)]) {
        swap(heaparr[index],heaparr[parent(index)]);
        index=parent(index);
    }
}

int extractMax() {
    if(heapsize==0) {
        cout << "\nNo elements in heap";
        return INT_MAX;
    }
    if(heapsize==1) {
        int ans=heaparr[0];
        heapsize--;
        return ans;
    }
    int ans=heaparr[0];
    heaparr[0]=heaparr[heapsize-1];
    heapsize--;
    heapifyDown(0);
    return ans;
}
int printMax() {
    if(heapsize==0) {
        cout << "\nNo elements in heap";
        return INT_MAX;
    }
    return heaparr[0];
}
void DeleteIndex(int index) {
    if(index>=heapsize) {
        cout<<"\nIndex out of range";
        return;
    }
    heaparr[index] = INT_MAX;
    while(hasParent(index) && heaparr[index] > heaparr[parent(index)]) {
        swap(heaparr[index],heaparr[parent(index)]);
        index=parent(index);
    }
    int removedElement=extractMax();
}

};

class HeapSort {
public:
vector<int> heaparr;
int capacity;
int heapsize;
HeapSort(vector<int>arr, int cap) {
    capacity = cap;
    heapsize = arr.size();
    heaparr = arr;
    heapSort();
}

void printHeap() {
    for(int i=0;i<heapsize;i++) {
        cout<<" " <<heaparr[i];
    }
}

bool hasParent(int i) {
    if((i-1)/2 >= 0) {
        return true;
    }
    return false;
}
bool hasLeft(int i) {
    if(2*i + 1 < heapsize) {
        return true;
    }
    return false;
}
bool hasRight(int i) {
    if(2*i + 2 < heapsize) {
        return true;
    }
    return false;
}
int left(int i) {
    return (2*i +1);
}
int right(int i) {
    return (2*i +2);
}
int parent(int i) {
    return (i-1)/2;
}
void swap(int&x, int&y) {
    int temp=x;
    x=y;
    y=temp;
}
int printMax() {
    if(heapsize==0) {
        cout << "\nNo elements in heap";
        return INT_MAX;
    }
    return heaparr[0];
}
void heapSort() {
    int n=heapsize;
    int lastNonLeafNode=(heapsize/2 -1);
    for(int i=lastNonLeafNode;i>=0;i--) {
        heapifyDownforHeapSort(i,n);
    }
    for(int i=n-1;i>0;i--) {
        swap(heaparr[0],heaparr[i]);
        heapifyDownforHeapSort(0,i); //calling heapify at index 0.
    }
}
void heapifyDownforHeapSort(int index, int n) {
    int largest = index;
    if(2*index + 1 < n && heaparr[left(index)] > heaparr[largest]) {
        largest=left(index);
    }
    if(2*index + 2 < n && heaparr[right(index)] > heaparr[largest]) {
        largest=right(index);
    }
    if(largest!=index) {
        swap(heaparr[index], heaparr[largest]);
        heapifyDownforHeapSort(largest,n);
    }
}
};
int main()
{
    int i=3;
    if(i==1) {
        //Building MaxHeap from Array.
        vector<int> arr{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
        MaxHeap H(arr,arr.size());
        H.printHeap();
    }
    if(i==2) {
        //Building MaxHeap from scratch
        MaxHeap H(11);
        H.insertKey(1);
        H.insertKey(3);
        H.insertKey(5);
        H.insertKey(4);
        H.insertKey(6);
        H.insertKey(13);
         //   H.printHeap();
        //    H.DeleteIndex(4);
       //     cout<<"\n\n\n";
        H.insertKey(10);
        H.insertKey(9);
        H.insertKey(8);
        H.insertKey(15);
        H.insertKey(17);
        H.printHeap();
    }
    if(i==3) {
        //HeapSort Here
        vector<int> arr{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
        HeapSort H(arr,arr.size());
        H.printHeap();
    }
    return 0;
}
