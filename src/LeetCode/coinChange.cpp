class Solution {
public:
    
    int coinChangeRecur(vector<int>& coins, int rem, vector<int>& memo) {
        if(rem<0) {
            return -1;
        }
        if(rem==0) {
            return 0;
        }
        if(memo[rem]!=0) {
            return memo[rem];
        }
        int min=INT_MAX;
        
        for(int i = 0; i < coins.size(); i++) {
            int res = coinChangeRecur(coins, rem - coins[i], memo);
            
            if(res>=0 && res<min) {
                min = 1 + res;
            }
        }
        if(min==INT_MAX) {  
            memo[rem]=-1;
        }
        else {
            memo[rem]=min;
        }
        return memo[rem];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) {
            return 0;
        }
        if(coins.size()==0) {
            return -1;
        }
        vector<int> memo(amount+1,0);
        int ans = coinChangeRecur(coins,amount,memo);
        return ans;
    }
    
    /*
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) {
            return 0;
        }
        if(coins.size()==0) {
            return -1;
        }
        
        vector<bool> visited(amount+1,false);
        queue<pair<int,int>> Q;   //<amount,steps till now>
        Q.push(make_pair(amount,0));
        visited[amount]=true;
        
        while(!Q.empty()) {
            pair<int,int> cur = Q.front();
            Q.pop();
            int curStep = cur.second;
            int curAmt = cur.first;
            for(int i=0;i<coins.size();i++) {
                
                int nextAmt = curAmt - coins[i];
                if(nextAmt == 0) {
                    return (curStep + 1);
                }
                if(nextAmt > 0 && visited[nextAmt]==false) {
                    visited[nextAmt]=true;
                    Q.push(make_pair(nextAmt, curStep + 1));
                }
            }
            
            
        }
        return -1;
    }
    */
    
};
