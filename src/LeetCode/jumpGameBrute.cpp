class Solution {
public:
    void jumpTo(int curpos,vector<int>& nums,bool& found) {
        int n=nums.size();
        if(found==true) {
            return;
        }
        if(curpos==n-1) {
            found=true;
            return;
        }
        if(curpos>=n) {
            return;
        }
        int i=1;
        while(i<=nums[curpos]) {
            jumpTo(curpos+i,nums,found);
            i++;
        }
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) {
            return false;
        }
        if(nums.size()==1) {
            return true;
        }
        bool found=false;
        jumpTo(0,nums,found);
        return found;
    }
};
