class Solution {
public:
    string enCode(string str) {
        sort(str.begin(),str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mainMap;
        
        
        int n=strs.size();
        for(int i=0; i<n; i++) {
            
            string curr_string = strs[i];
            string encoded = enCode(curr_string); 
            //encode it by sorted string. All different variations will have only one single encoded form. Push it to that map.
            mainMap[encoded].push_back(curr_string);
        }
        
        
        vector<vector<string>> result;
        
        for(unordered_map<string,vector<string>>::iterator it=mainMap.begin();it!=mainMap.end();it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};
