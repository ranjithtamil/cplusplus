class Solution {
public:
    int rob(vector<int>& nums) {
        int incl=0,excl=0;
        for(int i=0;i<nums.size();i++) {
            int temp=incl;
            incl=max(incl,nums[i]+excl);
            excl=max(temp,excl);
        }
        return max(incl,excl);
        /*
        int n=nums.size();
	    if(n==0) {
		    return 0;
	    }
	    vector<int> inclusive(n,0);
	    vector<int> exclusive(n,0);
	    inclusive[0]=nums[0];
	    exclusive[0]=0;
	    for(int i=1;i<n;i++) {
		    inclusive[i]=max(nums[i],nums[i]+exclusive[i-1]);
		    exclusive[i]=max(inclusive[i-1],exclusive[i-1]);
	    }
	    return max(exclusive[n-1],inclusive[n-1]);	
        */
    }
};
