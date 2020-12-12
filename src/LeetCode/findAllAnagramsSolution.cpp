class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pCount(26,0);
        int n=s.size();
        vector<int> result;
        
        for(int i=0;i<p.size();i++) {
            char c=p[i];
            
            pCount[c-'a']++;
        }
        if(s.size()<p.size()) {
            return result;
        }
        
        int i=0;
        int j=0;
        int countOfP=p.size();
        
        while(j<s.size()) {
            char c=s[j];
            pCount[c-'a']--;
            if(pCount[c-'a']>=0) {
                
                countOfP--;     //we found one character from p string in s
            }
            
            if(countOfP==0) {
                //we found all characters from p string in s
                result.push_back(i);
            }
            
            if(j-i+1 == p.size()) {
                pCount[s[i]-'a']++;
                if(pCount[s[i]-'a']>0) {
                    countOfP++;
                    //means if the first char in the window is a character in pCount
                }
                i++;
            }   
            j++;
        }
        
        return result;
    }
    /*
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26,0);
        vector<int> pCount(26,0);
        int n=s.size();
        vector<int> result;
        
        for(int i=0;i<p.size();i++) {
            char c=p[i];
            
            pCount[c-'a']++;
        }
        if(s.size()<p.size()) {
            return result;
        }
        
        for(int i=0;i<p.size();i++) {
            char c = s[i];
            
            sCount[c-'a']++;
        }
        for(int i=0,j=p.size()-1;j<s.size();i++,j++) {
            if(sCount==pCount) {
                result.push_back(i);
            }
            if(j+1 < n) {
                char c=s[j+1];
                sCount[c-'a']++;
                sCount[s[i]-'a']--;
            }
        }
        return result;
    }
    */
    /*
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        unordered_map<char,int>pDict;
        unordered_map<char,int>windowDict;
        
        for(int i=0;i<p.size();i++) {
            pDict[p[i]]++;
        }
        int required=pDict.size();
        int formed=0;
        int i=0;
        int j=0;
        while(j<s.size()) {
            windowDict[s[j]]++;
            if(pDict.find(s[j])!=pDict.end() && pDict[s[j]]==windowDict[s[j]]) {
                formed++;
            }
            while(i<=j && formed==required) {
                if(j-i+1 == p.size()) {
                    result.push_back(i);
                }
                
                if(pDict.find(s[i])!=pDict.end() && pDict[s[i]]==windowDict[s[i]]) {
                    formed--;
                    windowDict[s[i]]--;
                    i++;
                }
                else {
                    windowDict[s[i]]--;
                    i++;
                }
            }
            j++;
        }
        return result;
    }*/
};
