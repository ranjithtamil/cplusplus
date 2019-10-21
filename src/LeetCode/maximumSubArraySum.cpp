/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include<limits.h>
class Solution {
public:

    /* O(n) method
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int curr_max = nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++) {
            curr_max=max(nums[i],curr_max+nums[i]);
            max_so_far=max(max_so_far, curr_max);
        }
        return max_so_far;
    }
    */
    
    
    /* O(nlogn) method
    */
    int maxCross(vector<int>& nums, int l, int m, int h) {
        int left_sum = INT_MIN;
        int right_sum = INT_MIN;
        int sum=0;
        for(int i=m; i>=l; i--) {            
            sum=sum + nums[i];
            if(sum > left_sum) {
                left_sum=sum;
            }
        }
        sum=0;
        for(int j=m+1;j<=h;j++) { //j<=h important here
            sum=sum + nums[j];
            if(sum > right_sum) {
                right_sum=sum;
            }
        }
        
        return (left_sum + right_sum);
        
    }
    int maxArr(vector<int>& nums, int l,int h) {
        if(l==h) {
            return nums[l];
        }
        
        int m=(l+h)/2;
        
        int A=maxArr(nums,l,m);
        int B=maxArr(nums,m+1,h);
        int C=maxCross(nums,l,m,h);
        
        if(A>=B && A>=C) {
            return A;
        }
        else if(B>=A && B>=C) {
            return B;
        }
        else {
            return C;
        }
    }
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        int max=INT_MIN;
        max=maxArr(nums,0,n-1);
        return max; 
    }
    
    
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
