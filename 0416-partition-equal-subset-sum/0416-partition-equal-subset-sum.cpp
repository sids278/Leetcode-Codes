class Solution {
public:
    bool f(int indx, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(indx==0){
            return nums[indx]==target;
        }
        if(target==0){
            return 0;
        }
        if(dp[indx][target]!=-1){return dp[indx][target];}
        bool taken =0;
        if(target>=nums[indx]){
            taken=f(indx-1,target-nums[indx],nums,dp);
            
        }
        bool notTaken=f(indx-1,target,nums,dp);
        return dp[indx][target]=taken||notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        if(target%2==1){return false;}
        target=target/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};