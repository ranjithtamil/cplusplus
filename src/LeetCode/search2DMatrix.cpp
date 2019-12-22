/*
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

class Solution {
    //Change to iterative for lesser space.
public:
int findRow(vector<vector<int>>& matrix,int low,int high,int target) {
        if(low<=high) {
            int mid=(low+high)/2;
            int cols=(matrix[mid]).size();
        
            if(target >= matrix[mid][0] && target <= matrix[mid][cols-1]) {
                return mid;
            }
            if(target < matrix[mid][0]) {
                return findRow(matrix,low,mid-1,target);
            }
            if(target > matrix[mid][cols-1]) {
                return findRow(matrix,mid+1,high,target);
            } 
        }
        return 0;
    }
    
    bool bSearch( vector<int>& arr, int low, int high, int target) {
        if(low<=high) {
            int mid=(low+high)/2;
            if(target==arr[mid]) {
                return true;
            }
            if(target > arr[mid]) {
                return bSearch(arr,mid+1,high,target);
            }
            return bSearch(arr,low,mid-1,target);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) {
            return 0;
        }
        if(matrix.size()==1) { //for input [[]]
            int cols=matrix[0].size();
            if(cols==0) {
                return 0;
            }
        }
        int rows=matrix.size();
       
       
        int row=findRow(matrix, 0, rows-1, target);
        bool found=false;
        int n = matrix[row].size();
        if(n==0) {
            //can never be zero actually.
            return 0;
        }
        found=bSearch(matrix[row], 0, n-1, target);
        return found;
    }
};
