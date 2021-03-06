/*
https://www.youtube.com/watch?v=ohHWQf1HDfU&vl=en
https://www.youtube.com/watch?v=yBCzO0FpsVc

53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*///#include<bits/stdc++.h>
class Solution {
public:
    
    int maximum(int a, int b) {
        if(a>b) {
            return a;
        }
        return b;    
    }
    //Divide and Conquer Method - O(nlogn). O(n) is better solution.
    int maxSum(int a, int b, int c) {
        if(a>=b && a>=c) {
            return a;
        }
        if(b>=a && b>=c) {
            return b;
        }
        else {
            return c;
        }
    }
    int maxCrossSum(vector<int>& nums, int low, int mid, int high) {
        int leftSum=0;
        int rightSum=0;
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=mid;i>=low;i--) {
            sum=sum+nums[i];
            if(sum > maxSum) {
                maxSum=sum;
            }
        }
        leftSum=maxSum;
        sum=0,maxSum=INT_MIN;
        for(int i=mid+1;i<=high;i++) {
            sum=sum+nums[i];
            if(sum > maxSum) {
                maxSum=sum;
            }
        }
        rightSum=maxSum;
        
        int resultCrossSum=(leftSum+rightSum);
        return resultCrossSum;
        
    }
    int maxRecurSubArray(vector<int>& nums, int low, int high) {
        if(low==high) {
            return nums[low];
        }
        int mid=(low+high)/2;
        int leftSum=maxRecurSubArray(nums,low,mid);
        int rightSum=maxRecurSubArray(nums,mid+1,high);
        int crossSum=maxCrossSum(nums,low,mid,high);
       
        return maxSum(leftSum, rightSum, crossSum);
    }
    
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=maxRecurSubArray(nums,0,n-1);
        return maxSum;
    }
    
    /*
    //Naive - O(n^2) approach
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n<=0) {
            return 0;
        }
        int maxSum=nums[0];
        int sum=0;
        //int maxidx1=0;
        //int maxidx2=0;
        for(int i=0;i<n;i++) {
            int sum=0;
            for(int j=i;j<n;j++) {
                sum=sum+nums[j];
                if(sum > maxSum) {
                    maxSum=sum;
                    //maxidx1=i;
                    //maxidx2=j;
                    
                }
                
            }
        }
        //cout<<"\nIndices = "<<maxidx1<<" "<<maxidx2;
        return maxSum;
    }
    */
    
    /*
    O(n) solution
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int runningMax=nums[0];
        for(int i=1;i<n;i++) {
            runningMax=maximum(nums[i], runningMax+nums[i]);
            maxSum=maximum(maxSum, runningMax);
        }
        return maxSum;
    }
    */
    
    /* Kadane's algo - doesn't work when all numbers are negative and 0s.
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++) {
            if(nums[i-1]>0) {
                nums[i]=nums[i]+nums[i-1];
            }
        }
        int maxnum=0;
        for(int i=0;i<n;i++) {
            if(nums[i]>maxnum) {
                maxnum=nums[i];
            }
        }
        return maxnum;
    }
    */
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
