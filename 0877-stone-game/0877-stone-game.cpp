class Solution {
public:
    int f(int start,int end,vector<int>&nums,vector<vector<int>>&dp){
        if(start<0||end>=nums.size()||start>end)return 0;
        if(end-start==0)return nums[start];
        if(dp[start][end]!=-1)return dp[start][end];
        int first=nums[start]+min(f(start+2,end,nums,dp),f(start+1,end-1,nums,dp));
        
        int last=nums[end]+min(f(start,end-2,nums,dp),f(start+1,end-1,nums,dp));
        
        return dp[start][end]=max(first,last);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int alice=f(0,n-1,piles,dp);
        int bob=accumulate(piles.begin(),piles.end(), 0)-alice;
        return alice>bob;
    }
};