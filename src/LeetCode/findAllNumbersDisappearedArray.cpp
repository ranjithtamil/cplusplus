/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
Whichever number is present, mark that index to negative. In the end all the numbers whose missing will be having index marked as positive.

[4,3,2,7,8,3,2,1]

a[a[i]] = -a[i]

[-4,-3,-2,-7,8,3,-2,-1]

As 8 and 3 are positive and they are at index 5 and 6, so the missing numbers are 5 and 6
*/


class Solution {
public:
    int absol(int n) {
        if(n>0) {
            return n;
        }
        else {
            return (-1*n);
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();

        vector<int> result;
        for(int i=0;i<n;i++) {
            int idx=absol(nums[i]); //because the index may already be marked negative previously. You need to access positive index, hence absolute value.
            
            if(nums[idx-1] >0) {
                nums[idx-1]*= -1;
            }
        }
        
        for(int i=0;i<n;i++) {
            if(nums[i]>0) {
                result.push_back(i+1);
            }
        }
        return result;



        //Naive solution : use set - extra space
        /*
        int n=nums.size();
        unordered_set<int> mySet;
        vector<int> result;
        
        for(int i=0;i<n;i++) {
            mySet.insert(nums[i]);
        }
        
        for(int i=1;i<=n;i++) {
            if(mySet.find(i)==mySet.end()) {
                result.push_back(i);
            }
        }
        return result;
        */
        
    }
};
