class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int n=nums.size();
        int pivot=nums[l];
        while(l<h) {
            int pos = l+ (h-l)/2;
            if(pos-1 >=0 && nums[pos-1]>nums[pos]) {
                pivot=pos;
                return pivot;
            }
            if(pos+1 <n && nums[pos]>nums[pos+1]) {
                pivot=pos;
                return pivot;
            }
            if(nums[pos]<nums[l]) {
                h=pos-1;
            }
            else {
                l=pos+1;
            }
        }
        return pivot;
    }
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        if(n==0) {
            return -1;
        }
        if(n==1 && target==nums[0]) {
            return 0;
        }
        if(n==1 && target!=nums[0]) {
            return -1;
        }
        
        if(nums[n-1]>nums[0]) {
            //not rotated
            return binSearch(nums,0,n-1,target);
        }
        
        int pivot = findPivot(nums);
        if(target==nums[pivot]) {
            return pivot;
        }
        if(target < nums[0]) {
            return binSearch(nums,pivot+1,n-1,target);
        }
        else {
            return binSearch(nums,0,pivot-1,target);
        }
        return -1;      //if not found
    }
    int binSearch(vector<int>& nums, int low, int high, int target) {
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(target == nums[mid]) {
                return mid;
            }
            if(target > nums[mid]) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return -1;
    }
};
