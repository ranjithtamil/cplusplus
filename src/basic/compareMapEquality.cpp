//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string,string> map1;
    map<string,string> map2;
    map<string,string> map3;
    map1["hello"]="yes";
    map2["hello"]="yes";
    map3["hello"]="yes";
    
    
    map1["world"]="yes";
    map2["world"]="yes";
    map3["world"]="no";
    
    //compare map1 and map2
    bool flag=true;
    cout<<"\nMap1 and Map2 are : ";
    if(map1.size() == map2.size() ) {
        for( map<string,string>::iterator it=map1.begin(),  jt=map2.begin(); it!=map1.end(),jt!=map2.end(); it++,jt++ ) {
            if(*it != *jt) {
                cout<<"\nNot equal!";
                flag=false;
                break;

            }
        
        }
        if( flag == true ) {
            cout<<"\nequal!";
        }
    }
    else {
        cout<<"\nNot equal!";
    }
    
    
    
    //compare map1 and map3
    cout<<"\nMap1 and Map3 are : ";
    bool flag2=true;
    if(map1.size() == map3.size() ) {
        for( map<string,string>::iterator it=map1.begin(),  jt=map3.begin(); it!=map1.end(),jt!=map3.end(); it++,jt++ ) {
            if(*it != *jt) {
                cout<<"\nNot equal!";
                flag2=false;
                break;

            }
        
        }
        if( flag2 == true ) {
            cout<<"\nequal!";
        }
    }
    else {
        cout<<"\nNot equal!";
    }
    
    
    
    
    
    
    
    //compare map2 and map3
    cout<<"\nMap2 and Map3 are : ";
    bool flag3=true;
    if(map2.size() == map3.size() ) {
        for( map<string,string>::iterator it=map2.begin(),  jt=map3.begin(); it!=map2.end(),jt!=map3.end(); it++,jt++ ) {
            if(*it != *jt) {
                cout<<"\nNot equal!";
                flag3=false;
                break;

            }
        
        }
        if( flag3 == true ) {
            cout<<"\nequal!";
        }
    }
    else {
        cout<<"\nNot equal!";
    }
    
    
    
    
    return 0;
}
