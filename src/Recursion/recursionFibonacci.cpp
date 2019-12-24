//g++  5.4.0
//Fibonacci recursion
#include <iostream>
using namespace std;
int fibonacci(int num) {
    if(num==0) {
        return 0;
    }
    if(num==1) {
        return 1;
    }
    return (fibonacci(num-1) + fibonacci(num-2));
}
int main()
{
    int num=5;
    for(int i=0;i<=10;i++) {
        int res=fibonacci(i);
        cout<<"\n"<<res;
    }
    return 0;
}
