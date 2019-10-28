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

/*Brute Force */
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
