class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&dp,int target){
        for(int k=i-1;k>=0;k--){
            int diff=nums[i]-nums[k];
            if(diff<=target && diff>=(-target)){
                if(dp[k]>=0 && (dp[i]<dp[k]+1))dp[i]=dp[k]+1;
            }
        }
        return;

    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        int diff=nums[1]-nums[0];
        
        for(int i=1;i<n;i++){
            f(i,nums,dp,target);
            cout<<" value for "<<i<<" is "<<dp[i]<<endl;
        }
        return dp[n-1]>0?dp[n-1]:-1;
    }
};