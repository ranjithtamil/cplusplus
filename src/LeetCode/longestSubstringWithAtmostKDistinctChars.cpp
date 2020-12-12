class Solution {
public:
    char findMinKey(unordered_map<char,int>& pos, int& minPos) {
        int minVal=(pos.begin())->second;
        char minKey = (pos.begin())->first;
        for(unordered_map<char,int>::iterator it=pos.begin();it!=pos.end();it++) {
            if(it->second < minVal) {
                minVal=it->second;
                minKey = it->first;
            }
        }
        minPos=minVal;
        return minKey;
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k=2;   
        unordered_map<char,int>pos;      //char->recentpos
        int maxLen=0;
        int i=0;
        int j=0;
        int n=s.size();
        
        if(n==0) {
            return 0;
        }
       
        //set<char> seen;
        while(j<n) {
            char c=s[j];
            pos[c]=j;
            
            if(pos.size()<=k) {         //atmost... so smaller than or equal to k.
                maxLen=max(maxLen,j-i+1);
            }
            if(pos.size()>k) {
                int minPos=-1;
                char leftMost=findMinKey(pos,minPos);
                i=minPos+1;
                pos.erase(leftMost);
            }
            if(pos.size()==k) {
                maxLen=max(maxLen,j-i+1);
            }
            j++;                 
        }
        return maxLen;
    }
    /*
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k=2;
        
        set<char>seen;
        unordered_map<char,int> freq;
        int maxLen=0;
        int i=0;
        int j=0;
        int n=s.size();
        
        while(j<n) {
            freq[s[j]]++;
            seen.insert(s[j]);
            
            if(seen.size()==k) {
                maxLen=max(maxLen,j-i+1);
            }
            
            while(i<=j && seen.size()>k) {
                freq[s[i]]--;
                if(freq[s[i]]==0) {
                    seen.erase(s[i]);
                }
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    } */
};
