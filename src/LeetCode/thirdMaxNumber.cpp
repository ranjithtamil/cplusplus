class Solution {
public:
    //Do SinglePass solution and Multiple Pass Solution.
    int thirdMax(vector<int>& nums) {
        //Multiple Pass solution
        int MaxSoFar=INT_MIN;
        int seenINTMIN=0;
        int n=nums.size();
        set<int> maxSet;
        for(int p=0;p<n;p++) {
            if(nums[p]==INT_MIN) {
                seenINTMIN=1;
            }
        }
        int k=3; //Need 3 maximums, and the 3rd maximum
        for(int i=0;i<k;i++) {
            MaxSoFar=INT_MIN;
            for(int j=0;j<n;j++) {
                if(nums[j]>=MaxSoFar && maxSet.find(nums[j])==maxSet.end()) {
                    MaxSoFar = nums[j];
                }
            }
            if(MaxSoFar==INT_MIN) {
                if(seenINTMIN==1) {
                    maxSet.insert(MaxSoFar);    //add INT_MIN to the set only if it is in the array
                }
            }
            else {
                maxSet.insert(MaxSoFar);
            }
        }
        int MinSoFar=INT_MAX;
        MaxSoFar=INT_MIN;
        for(set<int>::iterator it=maxSet.begin();it!=maxSet.end();it++) {
            if(*it<=MinSoFar) {
                MinSoFar=*it;
            }
            if(*it>=MaxSoFar) {
                MaxSoFar=*it;
            }
        }
        if(maxSet.size()==3) {
            return MinSoFar;
        }
        return MaxSoFar;
    }
};
