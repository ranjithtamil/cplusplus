//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > permute(vector<int> &num);

void permuteRecursive(vector<int> &num,unsigned int begin, vector<vector<int> > &result);


vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    unsigned int a=0;
	    permuteRecursive(num, a, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, unsigned int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (unsigned int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
int main()
{
    vector<int> vecNums;
    vecNums.push_back(1);
    vecNums.push_back(2);
    vecNums.push_back(3);
    vector<vector<int>> result;
    
    result=permute(vecNums);
    //std::cout << "Hello, world!\n";
    
    
    for(unsigned int i=0;i<result.size();i++)
    {
        
        vector<int> temp;
        temp=result[i];
        
        for(unsigned int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
            
        }
        cout<<endl;
    }
}
