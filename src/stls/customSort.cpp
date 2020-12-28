
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Student {
    public:
    int age;
    string name;
    Student(int AGE, string NAME) {
        age = AGE;
        name = NAME;
    }
};
int main()
{
    Student A(35,"Alice");
    Student B(32,"Bob");
    Student C(45,"Cathy");
    Student D(10,"Dorothy");
    
    vector<Student> arr;
    arr.push_back(A);
    arr.push_back(B);
    arr.push_back(C);
    arr.push_back(D);
    
    sort(arr.begin(),arr.end(),[](Student X, Student Y) { 
        if(X.age <= Y.age) {
        return true;
    }
        return false;
    });
    
    cout<<"\n\nNames arranged by ascending order of age:\n";
    for(int i=0; i< arr.size(); i++) {
        cout<<"\n"<<arr[i].name;
    }

    return 0;
}
