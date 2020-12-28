class Solution {
public:
    //DP solution
    //Do Climbing stairs problem
    int numDecodings(string s) {
        int n=s.size();
        
        if(n==0) {
            return 0;
        }
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        
        if(s[0]=='0') {
            dp[1]=0;
        }
        else {
            dp[1]=1;
        }
        for(int i=2;i<dp.size();i++) {
            if(s[i-1]!='0') {
                dp[i]=dp[i]+dp[i-1];
            }
            
            string str = (s.substr(i-2,2));
            
            int num=stoi(str);
            if(num>=10 && num<=26) {
                dp[i]=dp[i]+dp[i-2];
            }
            
            
        }
        
        return dp[n];
    }
    /*
    unordered_map<int,int> myMap;
    int calcWays(int idx, string s) {
          //  cout<<"\nidx="<<idx;
       if(myMap[idx]) {
            return myMap[idx];
        }
         if(idx==s.size()) {
            return 1;
        }
        if(s[idx]=='0') {
            return 0;
        }
        if(idx==s.size()-1) {
            return 1;
        }
         
        int ans=calcWays(idx+1,s);
        //if(idx+2 < s.size()) {
            string num =  s.substr(idx,2);
        //cout<<"\nstringnum = "<<num;
            int numb = stoi(num);
        
          //      cout<<"\nnumb="<<numb;
            
            if(numb <= 26) {
            
                ans = ans + calcWays(idx+2,s);
            }
        //}
        
        myMap[idx]=ans;
        return ans;
    }
    int numDecodings(string s) {
        
        int ans=calcWays(0,s);
        return ans;
    }
    */
};
