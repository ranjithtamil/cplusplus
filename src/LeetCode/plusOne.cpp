/*
66. Plus One
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size() -1;
        while(carry==1 && n>=0) { //when n less than 0, donot try to access digits[n]
            int temp = (digits[n]) + 1;
            carry=(temp)/10;
            int sum=(temp)%10;
            digits[n]=sum;
            n--;
        }
        if(carry==1) {  //when there is remaining carry after everything, insert a 1 before the vector.
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
