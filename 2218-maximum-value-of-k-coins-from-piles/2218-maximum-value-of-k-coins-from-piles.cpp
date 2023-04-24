class Solution {
public:
    int solve(vector<vector<int>>&piles,int k,int i,vector<vector<int>>&dp){
        int  n = piles.size();
        if(k == 0 || i>=n)return 0;
        if(dp[k][i] != -1)return dp[k][i];
        // how many elements we can remove from it..
        int ans = 0;
        for(int j = 0;j<min(k,(int)piles[i].size());j++){
            //if i remove first jthe lement..
            ans = max(ans,piles[i][j]+solve(piles,k-(j+1),i+1,dp));
        }
        // remove not any elemment..
        ans = max(ans,solve(piles,k,i+1,dp));
        return dp[k][i] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = 0;j<piles[i].size();j++){
                sum += piles[i][j];
                piles[i][j] = sum;
            }
        }
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(piles,k,0,dp);
    }
};