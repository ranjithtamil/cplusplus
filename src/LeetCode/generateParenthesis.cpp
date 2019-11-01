/* 
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
(  https://www.youtube.com/watch?v=AdZIC_ygBnI  )
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/* Recursive Solution 
// Base case :- 
// 1. if ( number of open == number of closed == n ) { STOP recursion and push result }
// SubProblems :-
// 2. if ( number of open < n ) { Add Open Bracket } 
// 3. if ( number of closed < number of open ) { Add Closed Bracket }

class Solution {
public:
    vector<string>result;
    void generateCombs(int n,int Nopen,int Nclose,string str) {
        if(Nopen==Nclose && Nopen==n) {
           // cout<<"\n"<<str;
            result.push_back(str);
        }
        
        if(Nopen<n) {
            generateCombs(n,Nopen+1,Nclose,str+"(");
        }
        
        if(Nclose<Nopen) {
            generateCombs(n,Nopen,Nclose+1,str + ")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        int Nopen=0;
        int Nclose=0;
        generateCombs(n,Nopen,Nclose,str);
        
        return result;
    }
};

*/
