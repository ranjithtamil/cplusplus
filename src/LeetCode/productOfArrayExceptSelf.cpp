class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //based on soln.2 find left cumulative products and store in answer array. Then compute right cumulative products on fly and multiply with already stored left cumulative answers
        
        int n=nums.size();
        vector<int> ans(n);
        
        ans[0]=1;
        for(int i=1;i<n;i++) {
            ans[i]=ans[i-1]*nums[i-1];
        }
        //left cumulative products have been computed above
        
        int R=1;
        for(int i=n-1;i>=0;i--) {
            ans[i]=ans[i]*R;
            R=R*nums[i];
        }
        return ans;
    }
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        //based on soln.1 left side and right side of array cumulative products
        int n=nums.size();
        
        vector<int> ans;
        
        vector<int> left_array(n);
        vector<int> right_array(n);
        
        left_array[0]=nums[0];
        right_array[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++) {    
            left_array[i]=left_array[i-1] * nums[i];
        }
        
        for(int j=n-2;j>=0;j--) {
            right_array[j]=right_array[j+1] * nums[j];
        }
        
        
        
        for(int k=0;k<n;k++) {
            int left_ans=1;
            int right_ans=1;
            
            if(k>0) {
                left_ans=left_array[k-1];
            }
            if(k<n-1) {
                right_ans=right_array[k+1];
            }
            
            ans.push_back(left_ans*right_ans);
        }
        
        return ans;
    }
    */
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int product = 1;
        int cntZeros=0;
        for(int i=0;i<n;i++) {
            
            if(nums[i]==0) {
                cntZeros++;
            }
            else {
                product=product*nums[i];
            }
        }
        
        vector<int> result;
        
        for(int i=0;i<n;i++) {
            if(cntZeros>1) {                    //if there are more than 1 zero, then product will always be 0 (because atleast one 0 will be part of product)
                result.push_back(0);
            }
            else if(cntZeros==1 && nums[i]==0) {    //if count of zeros is 1, and current element is zero, then product does not contain zero. (nonzero)
                result.push_back(product);
            }
            else if(cntZeros==1 && nums[i]!=0) {    //if count of zeros is 1, and current element is not zero, then product contains the one zero.
                result.push_back(0);
            }
            else {
                result.push_back(product/nums[i]);  //else, product/(current element)  gives answer at that index.
            }
        }
        return result;
    }*/
};
