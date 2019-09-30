//Check whether power of four
// Number is power of four if :
// 1. Only one bit is set ( 4 = 0x100, 16 = 0x10000, 64 = 0x1000000)
// 2. Number of 0s after set bit is even ( 4 = 0x100 2 zeros, 16 = 0x10000 4 zeros, 64 = 0x1000000 6 zeros)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int check_power_of_four(int n) {
  int ct=0;
    if(n<=0) {
        return 0;
    }
    
  if (!(n&(n-1)) )  { //To check whether there is only one set bit ---- AND the number n, the number n-1 --- should give 0 if there is only one set bit.
      cout<<"\n N = "<<n;
    while(n > 1) {
      n = n>>1;
      ct++;
    }
    if(ct % 2 == 0) {
      return 1;
    }
    else {
      return 0;
    }
  }

}
int main() {
    int a = 20;
    int b = 16;
    int ret1=check_power_of_four(a);
    int ret2=check_power_of_four(b);
    cout<<"\n Is "<<a<<" power of four " <<ret1;
    cout<<"\n Is "<<b<<" power of four " <<ret2;
    
    return 0;   
}
