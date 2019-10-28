/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    int isPalindrome(string str) {
        int n=str.size();
        for(int i=0,j=n-1;i<j;i++,j--) {  
            if(str[i]!=str[j]) {
                return -1;
            }
        }
        return n;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string sub;
        int maxlen=0;
        string ans;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                sub=s.substr(i,j-i+1);   //substr(i,j-i+1)
                int curlen= isPalindrome(sub);
                if( curlen > maxlen ) {
                    maxlen= curlen;
                    ans = sub;
                }
            }
        }
        return ans;
    }
};
