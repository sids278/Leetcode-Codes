class Solution {
public:
//     int f(int i,int prev,int d,vector<int>&nums){
//         if(i==nums.size())return 0;
//         int pick=INT_MIN;
//         if(nums[i]-nums[prev]==d){
//             pick=1+f(i+1,i,d,nums);
//         }
//         else{
//             pick=f(i+1,prev,nums[i]-nums[prev],nums);
//         }
//         int newSeries=1+f(i+1,i,nums[i]-nums[prev],nums);
        
//         return max(newSeries,pick);
//     }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i]-nums[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};