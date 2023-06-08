class Solution {
public:
    int f(int i,vector<int>&nums,int rem,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(rem==0)return 0;
            return -1000000;
        }
        if(dp[i][rem]!=-1)return dp[i][rem];
        int take=nums[i]+f(i+1,nums,(rem+nums[i])%3,dp);
        int notTake=f(i+1,nums,rem,dp);
        return dp[i][rem]=max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f(0,nums,0,dp);
        
    }
};