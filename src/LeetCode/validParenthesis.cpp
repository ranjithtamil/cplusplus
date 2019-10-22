/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> mystack;
        if(s.empty()) {
            return true;
        }
        if(n==1) {
            return false;       //needs to always be a pair () or {} or []. There cannot be [ or ( or { alone.
        }        
        if(s[0]==')' || s[0]=='}' || s[0]==']') { //First character in string cannot be closing parenthesis!
            return false;
        }
        mystack.push(s[0]); //push first character onto stack
        char c;
        for(int i=1;i<n;) {
            if(mystack.empty()) {       //if stack is empty, push the character onto stack... Check if this is needed???
                mystack.push(s[i]);
                i++;
            }
            else {
                c=mystack.top();    //take the top from stack
                
                if(c!='(' && c!='{' && c!='[') {    //top of stack has to be any of opening parenthesis
                    return false;                   //because if it were closing parenthesis, we would have popped both the                                                     //start and close parenthesis from stack
                }
                    
                    
                if(c=='(') {          //if top of stack is '(', then next char should be starting parenthesis(,{,[ or 
                    if(s[i]!='{' && s[i]!='[' && s[i]!=')' && s[i]!='(') {  //corresponding ) parenthesis 
                        return false;
                    }
                    if(s[i]==')') {
                        mystack.pop();      //if next char is ) closing parenthesis, pop start, and do i++
                    }
                    if(s[i]=='[' || s[i]=='{' || s[i]=='(') {   //if next char is another start [{(, push it to stack, i++
                        mystack.push(s[i]);
                    }
                    i++;
                }
                else if(c=='{') {
                    if(s[i]!='(' && s[i]!='[' && s[i]!='}' && s[i]!='{') {
                        return false;
                    }
                    if(s[i]=='}') {
                        mystack.pop();
                    }
                    if(s[i]=='[' || s[i]=='(' || s[i]=='{') {
                        mystack.push(s[i]);
                    }
                    i++;
                }
                else if(c=='[') {
                    if(s[i]!='{' && s[i]!='[' && s[i]!=']' && s[i]!='(') {
                        return false;
                    }
                    if(s[i]==']') {
                        mystack.pop();
                    }
                    if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                        mystack.push(s[i]);
                    }
                    i++;
                }
                else {
                }
            }
        }
        if(!mystack.empty()) {      //at end of all operations, stack should ideally be empty.. there should not be
            return false;           //leftovers. If there are leftover remains, then its not valid parenthesis
        }
        return true;                //return true if all conditions meet
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
