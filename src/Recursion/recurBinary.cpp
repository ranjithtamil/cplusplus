//g++  5.4.0
//Recursive Binary Representation
#include <iostream>
using namespace std;
void binRep(int num) {
    if(num==0) {
        return;
    }
    binRep(num/2);
    cout<<(num%2);
}
int main()
{
    int num=20;
    binRep(20);
    return 0;
}
