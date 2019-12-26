217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true


    /* O(n) solution. Space = O(n)
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) {
            return 0;
        }
        unordered_set<int> mySet;
        
        for(int i=0;i<n;i++) {
            int temp=nums[i];
            if(mySet.find(temp)!=mySet.end()) {
                return 1;
            }
            else {
                mySet.insert(temp);
            }
        }
        return 0;  
    }
    */
    
    /* O(n*n) solution. Space=O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            int temp=nums[i];
            for(int j=i+1;j<n;j++) {
                if(temp==nums[j]) {
                    return 1;
                }
            }
        }
        return 0;
    }
    */
    
    /* O(nlogn) sorting. Space = O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int i=0,j=1;
        for(j;j<n;) {
            if(nums[i]==nums[j]) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
    */
