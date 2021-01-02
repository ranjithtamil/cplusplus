class Solution {
public:
    int rob(vector<int>& nums) {
        
        /*
        int incl=0,excl=0;
        for(int i=0;i<nums.size();i++) {
            int temp=incl;
            incl=max(incl,nums[i]+excl);
            excl=max(temp,excl);
        }
        
        return max(incl,excl);
        */
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
        
        
        //Below solution handles negatives as well
        int n=nums.size();
        
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return nums[0];
        }
        if(n==2) {
            return max(nums[0],nums[1]);
        }
        
        
        int second=nums[0];
        int first=nums[1];
        int current=nums[2];
        for(int i=2;i<n;i++) {
            current = maxmum(nums[i],nums[i]+second,first,second);
            second = max(first,second);
            first = current;
        }
        return current;
    }
    int maxmum(int a,int b, int c,int d) {
        if(a>=b && a>=c && a>=d) {
            return a;
        }
        if(b>=c && b>=a && b>=d) {
            return b;
        }
        if(c>=a && c>=b && c>=d) {
            return c;
        }
        return d;
    }
};
