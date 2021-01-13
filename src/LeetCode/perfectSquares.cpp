class Solution {
public:
    //https://www.youtube.com/watch?v=KaXeidsmvVQ
    //Perfect Explanation
    int numSquares(int n) {
        vector<int> dp(n+1,n);
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return 1;
        }
        
        
        
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<n+1;i++) {       //or i<=n
            
            for(int j=1; j*j<=i; j++) {
                
                dp[i]=min(dp[i], dp[i-(j*j)]+1);
                
            }
            
        }
        
        return dp[n];
    }
};
