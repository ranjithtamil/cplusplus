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
        
        
        cout<<"\nPermuteRecursive begin="<<begin<<" numvec = \n";
        //print
        
        for(unsigned int i=0;i<num.size();i++)
        {
            cout<<num[i]<<" ";
        }
        
        
        cout<<endl;
        cout<<"\nresultvec = \n";
        
        
        for(unsigned int k=0;k<result.size();k++)
        {
            vector<int> temp;
            temp=result[k];
            for(unsigned int j=0; j<temp.size();j++)
            {
            cout<<temp[j]<<" ";    
            }
            cout<<endl;
            
        }
        cout<<endl;
        
        
        
        
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


/*OUTPUT


PermuteRecursive begin=0 numvec = 
1 2 3 

resultvec = 


PermuteRecursive begin=1 numvec = 
1 2 3 

resultvec = 


PermuteRecursive begin=2 numvec = 
1 2 3 

resultvec = 


PermuteRecursive begin=3 numvec = 
1 2 3 

resultvec = 


PermuteRecursive begin=2 numvec = 
1 3 2 

resultvec = 
1 2 3 


PermuteRecursive begin=3 numvec = 
1 3 2 

resultvec = 
1 2 3 


PermuteRecursive begin=1 numvec = 
2 1 3 

resultvec = 
1 2 3 
1 3 2 


PermuteRecursive begin=2 numvec = 
2 1 3 

resultvec = 
1 2 3 
1 3 2 


PermuteRecursive begin=3 numvec = 
2 1 3 

resultvec = 
1 2 3 
1 3 2 


PermuteRecursive begin=2 numvec = 
2 3 1 

resultvec = 
1 2 3 
1 3 2 
2 1 3 


PermuteRecursive begin=3 numvec = 
2 3 1 

resultvec = 
1 2 3 
1 3 2 
2 1 3 


PermuteRecursive begin=1 numvec = 
3 2 1 

resultvec = 
1 2 3 
1 3 2 
2 1 3 
2 3 1 


PermuteRecursive begin=2 numvec = 
3 2 1 

resultvec = 
1 2 3 
1 3 2 
2 1 3 
2 3 1 


PermuteRecursive begin=3 numvec = 
3 2 1 

resultvec = 
1 2 3 
1 3 2 
2 1 3 
2 3 1 


PermuteRecursive begin=2 numvec = 
3 1 2 

resultvec = 
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 


PermuteRecursive begin=3 numvec = 
3 1 2 

resultvec = 
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 

1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 

*/





