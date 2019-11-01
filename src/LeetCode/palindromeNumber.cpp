/*
Using Extra Non-Constant space for string. 
9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        else if(x==0) { 
            return true;
        }
        else if((x%10==0) && x!=0) {
            return false; //for input 10, e.g. last digit=0 => first digit has to be zero. 
            //without this condition, rev/10==x (==0),so handle here
            //only if x==0 and x%10==0, it should return true. else return false here. Special Case!
        }
        int reversed_number=0;
        
        while(x>reversed_number) { //To only check until midway of integer. Sufficient to check for halfway through to avoid overflow
            int digit=x%10;
            x=x/10;
            reversed_number=(reversed_number*10) + digit;
        }
        
        if(reversed_number==x || (reversed_number/10)==x) {
                return true;
            // 1st condition(rev==x)if x has even digits. 2nd condition(rev/10==x)if x odd digits
        }
        else {
            return false;
        }
    }
};




/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        string str=to_string(x);
        
        int n=str.size();
        for(int i=0,j=n-1;i<=(n/2) && j>=i;i++,j--) {
            if(str[i]!=str[j]) {
                return false;
            }
        }
        return true;
        
    }
};
*/

