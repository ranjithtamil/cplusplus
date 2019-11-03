/* Leetcode Problem 46 */
/* See https://github.com/ranjithtamil/cplusplus/blob/master/src/math_problems/permutations_number.cpp */
/* 
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    void permuteRecur( vector<int>& nums, int begin, vector<vector<int>>& results) {
        int n = nums.size();
        if( begin >= n ) {
            results.push_back(nums);
            return;
        }
        else {
            for( int i=begin; i < n; i++ ) {
                swap(nums[i],nums[begin]);
                permuteRecur( nums, begin+1, results);
                swap(nums[i], nums[begin]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    
        vector<vector<int>> results;
        permuteRecur(nums, 0, results);
        return results;
    }
};
