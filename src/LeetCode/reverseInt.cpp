/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit 
signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your
function returns 0 when the reversed integer overflows.
*/

#include<math.h>
class Solution {
public:
    int reverse(int x) {
        
        
        
        int y=x,i=0;
        while(y!=0){
            y=y/10;
            i++;
        }
        
        if( x >= 2147483647 || x<= -2147483648) {
            return 0;
            
        }
        
        int v=0;
        
        if(x>=0) {
            while( x !=0 ) {
                cout<<"\n "<<v;
                if(v == 214748364) {
                    
                    if(x%10 > 7) {
                        return 0;
                    }
                    
                    
                }
                else if(v > 214748364) {
                    
                    return 0;
                }
                cout<<" "<<v;
               // v=v+((x%10) * pow(10,i-1));
                
                v=(v*10) + (x%10);
                i--;
                x=x/10;
            }    
        }
        
        else {
            
            while( x !=0 ) {
                
                if(v == -214748364) {
                    
                    if(x%10 < -8) {
                        return 0;
                    }
                    
                    
                }
                else if(v < -214748364) {
                    return 0;
                }
                v=(v*10) + (x%10);
                i--;
                x=x/10;
            }
            
        }
        
        
        return v;
    }
};


/* Solution Intuition 

Intuition

We can build up the reverse integer one digit at a time. 
While doing so, we can check beforehand whether or not appending another digit would cause overflow.

Algorithm -- Here rev = v, pop = x%10

Reversing an integer can be done similarly to reversing a string.

We want to repeatedly "pop" the last digit off of xx and "push" it to the back
of the rev. In the end, rev will be the reverse of the xx.

To "pop" and "push" digits without the help of some auxiliary stack/array, we can use math.

//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;
However, this approach is dangerous, because the statement temp = rev * 10 + pop = rev⋅10+pop can cause overflow.

Luckily, it is easy to check beforehand whether or this statement would cause an overflow.

To explain, lets assume that rev is positive.

If temp = rev* 10 + pop=rev⋅10+pop causes overflow, then it must be that rev >= INTMAX/10
 1. if (rev > INTMAX/10) , guaranteed overflow
 2. if (rev == INTMAX/10), AND pop>7 (i.e., x%10 > 7), then overflow
 
 
*/
