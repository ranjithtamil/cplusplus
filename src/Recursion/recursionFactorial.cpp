//g++  5.4.0
//Recursion Factorials
#include <iostream>
using namespace std;
int recurFact(int num) {
    if(num==1) {
        return 1;
    }
    return num*recurFact(num-1);
}
int iterFact(int num) {
    int fact=1;
    while(num>=1) {
        fact=fact*num;
        num--;
    }
    return fact;
}
int main()
{
    int num=5;
    if(num<=0) {
        int resRecur=1, resIter=1;
        cout<<"Result = "<<resRecur<<" = "<<resIter;
    }
    else {   
        int resRecur = recurFact(num);
        int resIter = iterFact(num);
        cout<<"Result = "<<resRecur<<" = "<<resIter;
    }
    return 0;
}
