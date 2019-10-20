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
