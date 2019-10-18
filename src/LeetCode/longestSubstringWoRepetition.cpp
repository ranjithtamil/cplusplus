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
