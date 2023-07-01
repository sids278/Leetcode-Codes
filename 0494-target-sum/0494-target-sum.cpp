class Solution {
public:
    
    int f(int inx,int target,int k,vector<int>&nums,vector<vector<int>>&dp,unsigned int offset){
        if(inx==nums.size()){
            return (target == k) ? 1 : 0;
        }
        if(dp[inx][target+offset]!=-1)return dp[inx][target+offset];
        int add=f(inx+1,target+nums[inx],k,nums,dp,offset);
        int red=f(inx+1,target-nums[inx],k,nums,dp,offset);
        return dp[inx][target+offset]=add+red;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unsigned int offset=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2*offset+1,-1));
        
        return f(0,0,target,nums,dp,offset);
    }
};