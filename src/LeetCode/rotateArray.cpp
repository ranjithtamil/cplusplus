/*
189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

class Solution {
public:
    void swap(int* a, int* b) {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void reverse(vector<int>& nums, int low,int high) {
        while(low<high) {
            swap(&nums[low],&nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k=k%n;
        //if(n!=1) { //if array size is 1, then array should remain same.
        reverse(nums,0,(n-k-1));
        reverse(nums,(n-k),n-1);
        reverse(nums,0,n-1);
        //}
    }
};
