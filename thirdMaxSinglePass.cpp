class Solution {
public:
    //Do SinglePass solution
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int> maxSet;
        int maxSoFar=INT_MIN;
        int seenINTMIN=0;
        
        for(int i=0;i<n;i++) {
            if(nums[i]==INT_MIN) {
                seenINTMIN=1;
            }
        }
        
        
        for(int i=0;i<n;i++) {
            if(nums[i]>=maxSoFar && maxSet.find(nums[i])==maxSet.end()) {
                maxSoFar=nums[i];
            }
            if(maxSoFar==INT_MIN) {
                if(seenINTMIN==1) {
                    maxSet.insert(maxSoFar);
                }
            }
            else {
                maxSet.insert(maxSoFar);
            }
            
            maxSoFar=INT_MIN;
            if(maxSet.size()==4) {
                int minSoFar=INT_MAX;
                for(set<int>::iterator it=maxSet.begin();it!=maxSet.end();it++) {
                    if(*it<=minSoFar) {
                        minSoFar=*it;
                    }
                }
                maxSet.erase(minSoFar);
            }
        }
        
        if(maxSet.size()==3) {
            int minMum=INT_MAX;
            for(set<int>::iterator it=maxSet.begin();it!=maxSet.end();it++) {
                if(*it<=minMum) {
                    minMum=*it;
                }
            }
            return minMum;
        }
        
        int maxMum=INT_MIN;
        for(set<int>::iterator it=maxSet.begin();it!=maxSet.end();it++) {
        if(*it>=maxMum) {
           maxMum=*it;
          }
        }
        return maxMum;
        //Single Pass solution
    }
};

//Single Passin Leetcode shows more time and space than Multiple Pass. Investigate ; TODO:
