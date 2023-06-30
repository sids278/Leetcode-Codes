class Solution {
public:
    
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        if(n<=2)return 1;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        for (int i=3; i<=n; i++) {
            for (int j=1; j<i; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};