
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    //string code="abcdddeeaaaaa";
    //string code="a";
    //string code="";
    //string code="aa";
    //string code="ab";
    //string code="aaa";
    //string code="aab";
    //string code="abc";
    string code="aabc";
    string result="";
    for( int i = 0; i < code.length(); i++){
        int count = 1;
        
        while(i < code.length() - 1 && code[i] == code[i + 1] ){
            count++;
            i++;
        }
        
        if(count>1) {
            result=result+to_string(count)+code[i];
        }
        else {
            result=result+code[i];
        }
        
    }
    cout<<"\n result = "<<result;
    return 0;
}
