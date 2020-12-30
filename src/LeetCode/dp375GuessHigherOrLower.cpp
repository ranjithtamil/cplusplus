class Solution {
public:
    //vector<vector<int>>dp;
    /* DP[Start,End] is dp[s,e] */
    
    /* dp[s,e] = min(k + max(dp[s,k-1], dp[k+1,e])) , where s<= k <= e */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        int x= dpFunc(1,n,dp);
        return x;
    }
    int dpFunc(int start, int end, vector<vector<int>>& dp) {
        if(start>=end) {
            return 0;
        }
        if(dp[start][end]!=0) {
            return dp[start][end];
        }
        int minValue=INT_MAX;
        
        for(int k=start;k<=end;k++) {
            int maxValue = k + dpFunc(start,k-1,dp);
            maxValue= max(maxValue, k+dpFunc(k+1,end,dp));
            minValue = min(minValue, maxValue);
        }
        dp[start][end]=minValue;
        return dp[start][end];  //or return minValue
    }
};


/*
https://www.youtube.com/watch?v=7TnjypshYNU

For eg:

Lets say, n=4, Then start=1, end=4
k runs from start to end

dp[start][end] = min {   for k=1 (i)   max( k + dp[start,k-1] , k + dp[k+1,end]) = max( 1 + dp[1,0],  1 + dp[2,4] ) = min { max( 1+0,1+3 )  = min {4,5,4,6} = 4
                         for k=2 (ii)  max( k + dp[start,k-1] , k + dp[k+1,end]) = max( 2 + dp[1,1],  2 + dp[3,4] ) =       max( 2+0,2+3 )
                         for k=3 (iii) max( k + dp[start,k-1] , k + dp[k+1,end]) = max( 3 + dp[1,2],  3 + dp[4,4] ) =       max( 3+1,3+0 ) 
                         for k=4 (iv)  max( k + dp[start,k-1] , k + dp[k+1,end]) = max( 4 + dp[1,3],  4 + dp[5,4] ) =       max( 4+2,4+0 ) }
                      }
                      
                = 4
*/
