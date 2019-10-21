/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        unsigned int i=0;
    
        
        for(vector<string>::iterator it=strs.begin();;it++) {
            
            if(it==strs.end()) {
              
                it=strs.begin();
                i++;
            }
            
            
            if(i == (*it).size()) {
                break;
            }
        
            if(( (*it)[i] ) != (strs[0])[i]) {
                break;
            }
         } 
        return (strs[0]).substr(0,i);
    }
};
