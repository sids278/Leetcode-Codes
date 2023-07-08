class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>c(n,1);
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]&& dp[i]<dp[prev]+1){
                    dp[i]=max(dp[i],1+dp[prev]);
                    c[i]=c[prev];
                }
                else if(nums[prev]<nums[i]&&dp[i]==dp[prev]+1){
                    c[i]+=c[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)cnt+=c[i];
        }
        return cnt;
    }
};