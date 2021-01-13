class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n,0);
        
        stack<int> myStack;
        
        result[n-1]=0;      //no further days for last element(/day)
        
        for(int i=n-1; i>=0; i--) {
            while(!myStack.empty() && T[myStack.top()]<=T[i]) {
                myStack.pop();
            }
            if(myStack.empty()) {
                result[i]=0;
            }
            else {
                result[i]=myStack.top()-i;
            }
            
            myStack.push(i);
        }
        return result;
    }
    /*
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> result;
        
        if(n==0) {
            return result;
        }
        if(n==1) {
            result.push_back(0);
            return result;
        }
        
        for(int i=0;i<n;i++) {
            result.push_back(0);
        }
        
        stack<pair<int,int>> myStack;
        myStack.push(make_pair(T[n-1],n-1));
        for(int i=n-2;i>=0;i--) {
            while(!myStack.empty() && myStack.top().first <= T[i]) {        //Smaller than equal to is very important.
                myStack.pop();
            }
            if(!myStack.empty() && myStack.top().first > T[i]) {
                result[i] = myStack.top().second - i;
            }
            myStack.push(make_pair(T[i],i));
        }
        return result;
    }
    */
};
