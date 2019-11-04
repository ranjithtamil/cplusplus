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














/* Array implementation Accepted Runtime : 200 ms , Memory 9MB (without substr function)*/

/*

//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        //int n1=s1.size(); //stupid leetcode counts "ab" as size 3 (includes " char as well)
        //int n2=s2.size();
        int n1=0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] >=97 && s1[i]<=122) {
                n1++;
            }
        }
        
        int n2=0;
        for(int i=0;i<s2.size();i++) {
            if(s2[i] >=97 && s2[i]<=122) {
                n2++;
            }
        }
        
        
        if( n1 > n2 ) {
            return false;
        }
        bool flag=true;
        int map1[26]={0};
        
        
        //Calculate histogram of characters for both string s1 and string s2
        for(int i=0; i<n1; i++) {
            if( s1.at(i) >= 97 && s1.at(i) <=122) {
                int val=s1.at(i) - 'a';                
                //cout<<"\n Updating map1["<<val<<"] from "<<map1[val] <<" to "<<map1[val]+1;
                map1[val]=map1[val]+1;
                
            }
        }
        
        for(int i=0; i<= n2 - n1; i++) {
            flag=true;
            int map2[26]={0};
            for(int j=0; j<n1; j++) {
                int val=s2.at(i+j)  - 'a';
                //cout<<"\n Updating map2["<<val<<"] from "<<map2[val] <<" to "<<map2[val]+1;
                map2[val]=map2[val]+1;
            }
            for(int l=0; l<26; l++) {
                if(map1[l]!=map2[l]) {                    
                    flag=false;
                }
            }
            if( flag == true ) {
                return flag;
            }
        }
        
        return flag;
    }
};
*/









/* Array Implementation with Substr Function (Runtime : 225ms, Memory: 60 MB)
//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        //int n1=s1.size(); //stupid leetcode counts "ab" as size 3 (includes " char as well)
        //int n2=s2.size();
        int n1=0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] >=97 && s1[i]<=122) {
                n1++;
            }
        }
        
        int n2=0;
        for(int i=0;i<s2.size();i++) {
            if(s2[i] >=97 && s2[i]<=122) {
                n2++;
            }
        }
        
        
        if( n1 > n2 ) {
            return false;
        }
        bool flag=true;
        int map1[26]={0};
        
        
        //Calculate histogram of characters for both string s1 and string s2
        for(int i=0; i<n1; i++) {
            if( s1.at(i) >= 97 && s1.at(i) <=122) {
                int val=int(s1.at(i)) - int('a');
                map1[val]=map1[val]+1;
                
            }
        }
        
        
        
        for(int i=0; i<= (n2 - n1); i++) {
                flag=true; //last iteration couldve set to false. toggle it to true again
                int j=(i+n1-1);
                string sub = s2.substr(i,j-i+1);
                int map2[26]={0};
                //Calculate histogram of all possible substrings of length n1=s1.size() in string s2 
                for(int k=0; k<n1; k++) {
                    if( sub.at(k) >=97 && sub.at(k) <= 122) {
                        int val=int(sub.at(k)) - int('a');
                         map2[val]=map2[val]+1;
                    }
                }
            
                //compare both the histograms of s1 and (substring of s2)
                for(int l=0; l<26; l++) {
                    if(map1[l]!=map2[l]) {
                        flag=false;
                    }
                }
                if(flag==true) {
                    return true;
                }
            
               
        }
        
        return flag;
    }
};


*/
