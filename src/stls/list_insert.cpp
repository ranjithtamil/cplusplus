//g++  5.4.0
//https://www.studytonight.com/cpp/stl/stl-container-list
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <algorithm>
using namespace std;

int main()
{

list<int> list1;
list<int> list2{1,2,3};
list<int> list3{11};

    
//So 100    
list<int>::const_iterator it1;
it1=list1.begin();

list1.insert(it1,100); //list1 = (100->NULL)
cout<<"\nList1:\n";
it1=list1.begin();    
while(it1!=list1.end())
{
    cout<<endl<<(*it1);
    it1++;
}
    

    
//So 1 999 2 3     
    
list<int>::iterator it2;
it2=list2.begin();    
list2.insert(next(it2,1),999); //list2 = (1->999->2->3)
cout<<"\nList2:\n";    
while(it2!=list2.end())
{
    cout<<endl<<(*it2);
    it2++;
}    
    
    
//create new list list4(1->9999) and copy list 2 to (just before 9999 in list4)
//So 1 1 999 2 3 9999    
list<int> list4{1,9999};    
list4.insert(next(list4.begin(),1),list2.begin(),list2.end());
list<int>::iterator it4=list4.begin();    
cout<<"\nList4:\n";    
while(it4!=list4.end())
{
    cout<<endl<<(*it4);
    it4++;
}        
    
    
//insert 11 in list3(10) 5 times before (list3.begin())
//So 10 10 10 10 10 11    
list3.insert(list3.begin(),5,10);
list<int>::iterator it3=list3.begin();    
cout<<"\nList3:\n";    
while(it3!=list3.end())
{
    cout<<endl<<(*it3);
    it3++;
}        
    
    

return 0;    
}
