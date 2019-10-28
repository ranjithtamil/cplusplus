/*
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j) {
            int mid=(i+j)/2;
            if(target==nums[mid]) {
                return mid;
            }
            else if(target > nums[mid]) {
                i=mid+1;
            }
            else {
                j=mid-1;
            }
        }
        //you reach here if element is not found... check? (i==j at this point ?? )
        if( target > nums[i]) {   
            return (i+1); //if target is greater than i, index to be placed is (i+1)
        }
        else {
            return i; //if target is smaller than i, index to be placed is (i)
        }
        
    }
};
