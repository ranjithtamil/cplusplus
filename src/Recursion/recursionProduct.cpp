#include <iostream>
using namespace std;
int product(int a, int b) {
    if(a<b) {
        return product(b,a);
    }
    
    if(b!=0) {
        return a+(product(a,b-1));
    }
    else {
        return 0;
    }
}
int main()
{
    int a=5;
    int b=2;
    int res=product(a,b);
    cout<<"\nProduct = "<<res;
    return 0;
}
