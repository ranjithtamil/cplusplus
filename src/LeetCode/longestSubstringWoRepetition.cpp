/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
            Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
            
Extra edge case Input: "abba"
Output: 2
*/
class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen=0;
        int n=s.size();
        for(int j=0,i=0;j<n;) {
            if(seen.find(s[j])==seen.end()) {
               seen.insert(s[j]);
               maxLen=max(maxLen,j-i+1);
                j++;
            }
            else {
                seen.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }*/
  /*SLIDING WINDOW MOST OPTIMIZED MAP SOLUTION
            int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> posMap;
        int maxLen=0;
        int n=s.size();
        for(int j=0,i=0;j<n;j++) {
            if(posMap.find(s[j])!=posMap.end()) {
                
                i=max(i,posMap[s[j]]+1);
                posMap[s[j]]=j;  
                maxLen=max(maxLen,j-i+1);
            }
            else {
                posMap[s[j]]=j;
                maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
    
    // If maxLen is not recorded in both if and else conditions - say it was only recorded in case of the else condition, then this test case will fail!!! Because when you hit the second t,its already present in map. If maxLen recording not done in the if case, then maxLen will not have the last 't' char, and j++ will exit out of loop. So you will record maxLen as 4.
    
    //So, if the maxlen condition was there in the else case also, then maxLen will be recorded after updating posMap[s[j]] and i. So you will record maxLen as 5.
/*Input:
"tmmzuxt"
Output:
4
Expected:
5*/ 
};
*/
/* SLIDING WINDOW OPTIMIZED (MAP) */
#include<bits/stdc++.h>
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        map<char,int> mymap;
        
        int i=0,j=0,maxlen=0,n=s.size();
        for(;j<n;j++) {
            if( mymap.find(s.at(j))!= mymap.end() ) {
                
                i = max(i,mymap[s[j]]); //abba edge case...  when you hit the last 'a', you want i=3.... you dont want i=0 i.e. i = max(3,0).. 
            }
            maxlen = max(maxlen, j-i +1);
            mymap[s[j]]=j+1;
        }
        return maxlen;
    }
};



/* SUBOPTIMAL TWO PASS SLIDING WINDOW (SET) */
/*
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        set<char> myset;
        unsigned int n = s.size();
       
        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int maxlen=0;
        while( i<n && j<n) {
            if( myset.find(s[j]) == myset.end() ) {
                 //both i and j are 0 initially. j++ to next substring element
                myset.insert(s[j]); //insert s[j] 0th element
                j++;
                maxlen = max(j-i, maxlen); //(1-0, 0)
            }
            else {
                myset.erase(s[i]);
                i++;
            }
        }
        return maxlen;
    }
};
*/


/* BRUTE FORCE SOLUTION 

class Solution {
public:
    int isDuplicate(string s) {
        set<char> myset;
        int length=0;
        for( string::iterator it = s.begin(); it!= s.end(); it++ ) {
            if( myset.find(*it) == myset.end() ) {
                myset.insert(*it);
                length++;
            }
            else {
                return length;
            }
            
        }
        return length;
    }
    int lengthOfLongestSubstring(string s) {
        //brute force
        int max_sub_length=0;
        int n = s.size();
        //Important corner case - when there is only one element!!
        if( n == 1 ) {
            return 1; // If there is only one character in string, then return max_substring_length = 1
        }
        
        for( int i = 0; i < n-1; i++ ) {
            for( int j = i + 1; j < n; j++ ) {
                string str;
                str.assign( s.begin() + i, s.begin() + (j+1) ); //Very important str.assign (0,2) for abcxyz = ab. str.assign (0,1) for defghi = d
                max_sub_length = max( max_sub_length, isDuplicate( str ));
                
            }
        }
        return max_sub_length;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

 END OF BRUTE FORCE SOLUTION */
