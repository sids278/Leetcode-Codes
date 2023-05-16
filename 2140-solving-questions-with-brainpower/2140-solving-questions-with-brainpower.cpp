class Solution {
public:
    long long f(int indx, int n,vector<vector<int>>&nums,vector<long long>&dp){
        if(indx>=n){return 0;}
        if(dp[indx]!=-1){return dp[indx];}
        long long seleco=nums[indx][0]+f(indx+1+nums[indx][1],n,nums,dp);
        long long ignoro=f(indx+1,n,nums,dp);
        dp[indx]=max(seleco,ignoro);
        
        return dp[indx];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return f(0,n,questions,dp);
    }
};
