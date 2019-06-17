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
   
    //Search for element 2, and insert 5 before it
    list<int>::iterator it=list2.begin();    
  
    
    
    while(it!=list2.end())
    {        
        if(*it==2)
        {
            break;
        }
        ++it;
    }
   
    list2.insert(it,5);    
    
    for(list<int>::iterator it=list2.begin();it!=list2.end();it++)
    {
        cout<<(*it)<<endl;
    }
    
    
    //Remove element given value. Remove value 2
    
    //Remove by value - Remove all occurrences of 2
    
    list2.remove(2);
    
    cout<<"\n\nRemoved 2: Display \n\n";
    
    
    for(list<int>::iterator it=list2.begin();it!=list2.end();it++)
    {
        cout<<(*it)<<endl;
    }
    
    //Remove element given position. Remove value 5 after searching for its position. Can be controlled to remove only first occurrence (or) first n occurrences
    
    list<int>::iterator it_remove;
    for(list<int>::iterator it=list2.begin();it!=list2.end();it++)
    {
     if(*it==5)
     {
      it_remove=it;
      
     }
    }
    
    list2.erase(it_remove);
    
    
     cout<<"\n\nRemoved 5: Display \n\n";
    
    
    for(list<int>::iterator it=list2.begin();it!=list2.end();it++)
    {
        cout<<(*it)<<endl;
    }
    
    return 0;    
}
