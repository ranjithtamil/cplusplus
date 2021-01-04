

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    double median;
    // initialize your data structure here. /
    MedianFinder() {
        median = 0.0;
    }
    
    void addNum(int num) {
        if(minHeap.size()==0 && maxHeap.size()==0) {
            median = num;
            maxHeap.push(num);
            return;
        }
        
        if(minHeap.size()==0 && maxHeap.size()==1) {
            median = (num + maxHeap.top())*0.5;
            if(num >= maxHeap.top()) {
                minHeap.push(num);
                return;
            }
            else {
                int maxHeapTop = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(maxHeapTop);
                return;
            }
        }
        
        if(maxHeap.size()==minHeap.size()) {
            if(num >= minHeap.top()) {
                median = minHeap.top();
                int minHeapTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minHeapTop);
                minHeap.push(num);
                return;
            }
            else {
                median = max(maxHeap.top(),num);
                maxHeap.push(num);
                return;
            }
        }
        
        if(maxHeap.size()> minHeap.size()) {
            if(num < maxHeap.top()) {
                int maxHeapTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxHeapTop);
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) * 0.5;
                return;
            }
            else if(num > maxHeap.top()) {
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) * 0.5;
                return;
            }
            else {  //i.e., num == maxHeap.top()
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) * 0.5;
                return;
            }
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return median;
    }
};


/*
class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};
*/











/*
class MedianFinder {
public:
    vector<int> store;
    // initialize your data structure here. /
    MedianFinder() {
        
    }
    
    void addNum(int num) {
     if (store.empty())
            store.push_back(num);
        else
            store.insert(upper_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};
*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
