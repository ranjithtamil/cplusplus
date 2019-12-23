#include <iostream>
using namespace std;
int sumArray(int a[], int no) {
    if(no==0) {
        return a[0];
    }
    return a[no]+sumArray(a,no-1);
}
int main()
{
    int a[]={5,6,5,5,5,5,5};
    int n=(sizeof(a)/sizeof(int));
    int res=sumArray(a,n-1);
    cout<<res;
    return 0;
}
