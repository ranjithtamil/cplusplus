//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
class Solution {
public:
    void swaps(int &x, int &y) {
        int temp=x;
        x=y;
        y=temp;
    }
    int partition(int low, int high, vector<int>& nums) {
        int pivot=nums[high];
        int i=low-1;
        for(int j=low;j<=high-1;j++) {
            if(nums[j]<pivot) {
                i++;
                swaps(nums[i],nums[j]);
            }
        }
        swaps(nums[i+1],nums[high]);
        return (i+1);
    }
    int quickSelect(int low,int high,vector<int>& nums,int k) {
        if(low==high) {
            return nums[low];
        }
        int pivot=partition(low,high,nums);
        int n=nums.size();
        if(pivot==n-k) {
            return nums[pivot];
        }
        if(pivot>(n-k)) {
            return quickSelect(low, pivot-1, nums, k);
        }
        if(pivot<(n-k)) {
            return quickSelect(pivot+1, high, nums, k);
        }
        return INT_MAX;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int low=0;
        int high=nums.size()-1;
        return quickSelect(low,high,nums,k);
    }
    //Heap optimized-while adding elements to heap(MINHEAP), keep popping off of heap to keep only k elements in heap. last element in heap will be MAX.
    /*
      int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) {
            return -1;
        }
        if(n==0) {
            return -1;
        }
        if(n==1 && k==1) {
            return nums[0];
        }
        priority_queue<int> hp;
        int numsAdded=0;
        int element=INT_MIN;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++) {
            hp.push(*it * -1);
            if(hp.size()>k) {
                //cout<<"\nEl = "<<hp.top();
                hp.pop();       //popped elements are smallest elements
            }
        }
        
        if(!hp.empty()) {
            element=hp.top();
        }
        return element*-1;
      }
    */
    /*
      int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) {
            return -1;
        }
        if(n==0) {
            return -1;
        }
        if(n==1 && k==1) {
            return nums[0];
        }
        make_heap(nums.begin(),nums.end());
        
        int element=INT_MIN;
        for(int i=0;i<k;i++) {
            if(!nums.empty()) {
                element=nums.front();
                pop_heap(nums.begin(),nums.end());
                nums.pop_back();
            }
        }
        return element;
    }
    */
    /*
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) {
            return -1;
        }
        if(n==0) {
            return -1;
        }
        if(n==1 && k==1) {
            return nums[0];
        }
        priority_queue<int> hp;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++) {
            hp.push(*it);
        }
        
        int element=INT_MIN;
        for(int i=0;i<k;i++) {
            if(!hp.empty()) {
                element=hp.top();
                hp.pop();
            }
        }
        return element;
    }
    */
    /*
    //This is to find Unique K Largest Elements , so use a set to find only unique ones
    int findKthLargestWhichIsUnique(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) {                   //instead of this,you need to compare with size of set(k > mySet.size())
            return -1;
        }
        if(n==0) {
            return -1;
        }
        if(n==1 && k==1) {
            return nums[0];
        }
        
        
        set<int> mySet(nums.begin(),nums.end());
        priority_queue<int> hp;
        
        for(set<int>::iterator it=mySet.begin();it!=mySet.end();it++) {
            hp.push(*it);
        }
        
        int i=0;
        int element=0;
        while(i<k) {
            if(!hp.empty()) {
                element=hp.top();
                //
                cout<<"\nEl = "<<element;
                //
                hp.pop();
            }
            else {
                cout<<"\nhp Is empty";
            }
            i++;
        }
        return element;
    }*/
};
