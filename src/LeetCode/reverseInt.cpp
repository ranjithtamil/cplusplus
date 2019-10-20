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

Algorithm

Reversing an integer can be done similarly to reversing a string.

We want to repeatedly "pop" the last digit off of xx and "push" it to the back
of the \text{rev}rev. In the end, \text{rev}rev will be the reverse of the xx.

To "pop" and "push" digits without the help of some auxiliary stack/array, we can use math.

//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;
However, this approach is dangerous, because the statement \text{temp} = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop can cause overflow.

Luckily, it is easy to check beforehand whether or this statement would cause an overflow.

To explain, lets assume that \text{rev}rev is positive.

If temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop causes overflow, then it must be that \text{rev} \geq \frac{INTMAX}{10}rev≥ 
10
INTMAX
​	
 
If \text{rev} > \frac{INTMAX}{10}rev> 
10
INTMAX
​	
 , then temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop is guaranteed to overflow.
If \text{rev} == \frac{INTMAX}{10}rev== 
10
INTMAX
​	
 , then temp = \text{rev} \cdot 10 + \text{pop}temp=rev⋅10+pop will overflow if and only if \text{pop} > 7pop>7
Similar logic can be applied when \text{rev}rev is negative.
*/
