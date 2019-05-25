
#include <iostream>
using namespace std;
void func1(int*,int*);
void func2(int&, int&);
int main()
{
    //std::cout << "Hello, world!\n";
    int foo=50;
    auto bar=foo;
    
    cout<<bar<<endl;
    decltype(foo) barr;
    barr=55.45;
    cout<<barr<<endl;
    
    int x=10;
    int y=++x;
    cout<<y<<endl;
    
    int x1=10;
    int y1=x1++;
    cout<<y1<<endl;
    
    /*Pass by Pointer Method*/
    
    int pass1=10,pass2=20;
    func1(&pass1,&pass2);
    
    cout<<pass1<<endl<<pass2<<endl;
    
    /*Pass by reference method*/
    func2(pass1,pass2);
    cout<<pass1<<endl<<pass2<<endl;
    
}

void func1(int* recv1,int* recv2)
{
    
    *recv1=100;
    *recv2=200;
    
}

void func2(int& recv1,int& recv2)
{
    recv1=500;
    recv2=1000;
}

