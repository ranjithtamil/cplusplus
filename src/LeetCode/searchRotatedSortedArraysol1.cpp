class Solution {
public:
    void binSearch(vector<int>& nums,int l,int r,int& foundIndex, int target) {
        while(l<=r) {
            int m = l + (r-l)/2;
            if(target > nums[m]) {
                l=m+1;
            }
            else if(target < nums[m]) {
                r=m-1;
            }
            else {
                foundIndex=m;
                return;
            }
        }
    }
    int findPivot(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        
        if(nums[l]<nums[r]) {
            return -1;
        }
        
        while(l<=r) {
            int mid=(l + (r-l/2));
            if(mid>0 && nums[mid]<nums[mid-1]) {
                return mid;
            }
            /*if(mid<(n-1) && nums[mid+1]<nums[mid]) {
                return mid+1;
            }*/
            if(nums[mid]<nums[l]) {
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        
        return -1;
        /*
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i]<nums[i-1]) {
                return i;
            }
        }
        return -1;
        */
    }
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        if(n==0) {
            return -1;
        }
        if(n==1) {
            if(nums[0]==target) {
                return 0;
            }
            return -1;
        }
        int pivotIndex = findPivot(nums);
        int foundIndex=-1;
        if(pivotIndex == -1) {  //if there is no Pivot in array
            binSearch(nums,0,n-1,foundIndex,target);            //if no Pivot, do normal bSearch(0,n-1)
            return foundIndex;
        }
        if(nums[pivotIndex]==target) {      //be careful to have this condition before the next if condition. Because in the case of [5,1,3] and you're searching for 3, then you want to search the pivot index for the element first. If not found, you can go to the next if condition and search between 0 and n-2. Okay....
            return pivotIndex;
        }
        
        /*
        if(pivotIndex == n-1) {         //if pivot is last element, do bSearch(0,n-2)
            binSearch(nums,0,n-2,foundIndex, target);
            return foundIndex;
        }
        */
        
        if(target < nums[0]) {      //if target is greater than first element, then bSearch(pivot+1,n-1)
            binSearch(nums,pivotIndex+1,n-1,foundIndex, target);
        }
        else {                  //if target is smaller than first element, then bSearch(0, pivot-1)
            binSearch(nums,0,pivotIndex-1,foundIndex,target);
        }
        return foundIndex;
    }
};
