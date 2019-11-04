/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

/*
//BRUTE FORCE SOLUTION
class Solution {
public:
    bool checkSubstring(string sub, string s2) {
        int i=0;
        int j=0;
        if(sub.size()==0 && s2.size()!=0) {
            return false;
        }
        if(sub.size()==0 && s2.size()==0) {
            return true;
        }
        
        //eg: "ba" and "eidbaooo" 
        //if corresponding indices match, i++ and j++. 
        //else i=0(reset), and j++(to check for possible match).
        
        while( i<sub.size() && j<s2.size()) {
            if(sub[i]==s2[j]) {
                i++;
                j++;
            }
            else {
                i=0;
                j++;
            }
        }
        
        //if after looping, i is not reset, but hits i.size(), then it means all characters of sub matched. hence, true.
        
        if(i==sub.size()) {
            //cout<<"\nsub = "<<sub<<"\ns2 = "<<s2;
            return true;
        }
        else {
            return false;
        }
        
    }
    void generatePerms(string prefix, string suffix, vector<string> &allPerms) {
        int n=suffix.size();
        if( n == 0) {
            allPerms.push_back(prefix);
        }
        else {
            for(int i=0; i<n; i++) {
                generatePerms( prefix + suffix.at(i), suffix.substr(0,i) + suffix.substr(i+1,n), allPerms);
            }
        }
    }
    bool checkInclusion(string s1, string s2) {
        vector<string> allPerms;
        string prefix="";
        string suffix=s1; 
        
        //Generate all possible permutations of string s1. Result is a 'vector<string> allPerms'.
        generatePerms(prefix,suffix,allPerms);
        
        for(int i=0;i<allPerms.size(); i++) {
            //cout<<allPerms.at(i)<<" ";
            //For each permutation of s1, check whether it is a substring of s2 (in exact order).
            
            bool val=checkSubstring(allPerms.at(i), s2);
            if(val==true) {
                return true;
            }
        }
        
        
        //If none of the permutations exactly match, return false
        return false;
    }
};
*/
