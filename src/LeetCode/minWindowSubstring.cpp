/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include<bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) {
            return "";
        }
        map<char,int> mymap;
        for(int i=0;i<t.size();i++) {
            mymap[t[i]]++;
        }
        
        int required=mymap.size(); //no of unique characters in t
        
        //formed = (no of unique characters of t) in the window
        int formed = 0, l=0,r=0;
        
        
        //Dictionary to count unique characters in window
        map<char,int> windowCounts;
        
        int ans[]={-1,0,0}; //(window length, left, right)
        
       
        while( r < s.length()) {
            char c = s[r]; //character from right end of string
            
            windowCounts[c]++;
            
            if( (mymap.find(c)!= mymap.end())  && windowCounts[c]==mymap[c]) {
                formed++;
            }
            
            while(l<=r && formed == required) {
                c = s[l];
                
                if( ans[0]==-1 || (r-l +1)<ans[0]) {
                    ans[0]=r-l+1;
                    ans[1]=l;
                    ans[2]=r;
                }
                
                windowCounts[c]--;
                
                if(mymap.find(c)!=mymap.end()  &&  windowCounts[c]<mymap[c]) {
                    formed--;
                }
                l++;
            }
            r++;
            
        }
        
        if(ans[0]==-1) {
            return "";
        }
        else {
            return s.substr(ans[1], ans[2]-ans[1]+1);
        }
    }
};
