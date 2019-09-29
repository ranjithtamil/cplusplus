//Check whether power of four
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int check_power_of_four(int x) {
    if(x==0)
        return 0;
    
    while(x!=1) {
     
        if( (x % 4) != 0) {
            return 0;
        }
       
        x=(x/4);
        
    }
    return 1;

}
int main() {
    int a = 24;
    int b = 16;
    int ret1=check_power_of_four(a);
    int ret2=check_power_of_four(b);
    cout<<"\n Is "<<a<<" power of four " <<ret1;
    cout<<"\n Is "<<b<<" power of four " <<ret2;
    
    return 0;   
}
