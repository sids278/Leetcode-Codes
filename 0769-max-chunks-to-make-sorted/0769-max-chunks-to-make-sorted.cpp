class Solution {
public:
    int dp[11];
    int sol(vector<int> &arr, int i, int n,int preMax){
        if(i>=n)return 0;
        if(preMax>*min_element(arr.begin()+i,arr.end()))return INT_MIN/2;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN/2;
        for(int k=i;k<n;k++){
            int prev=*max_element(arr.begin()+i,arr.begin()+k+1);
            int temp=1+sol(arr,k+1,n,prev);
            ans=max(temp,ans);
        }
        return dp[i]=ans;
    }
    int maxChunksToSorted(vector<int>& arr) {
        memset(dp,-1,sizeof dp);
        return sol(arr,0,arr.size(),INT_MIN);
    }
    // below here is my code very identical but not working idk y
//     int f(int i, int prev, vector<int>& nums, vector<int>& dp) {
//         int n = nums.size();
//         if (i >= n) return 0;
//         if (prev > *max_element(nums.begin() + i, nums.end())) return INT_MAX / 2; // Compare with maximum element
//         if (dp[i] != -1) return dp[i];
//         int ans = INT_MIN / 2;

//         for (int k = i; k < n; k++) {
//             int prev2 = *max_element(nums.begin() + i, nums.begin() + k + 1); // Update with maximum element
//             int temp = 1 + f(k + 1, prev2, nums, dp);
//             ans = max(temp, ans);
//         }
//         return dp[i] = ans;
//     }

//     int maxChunksToSorted(vector<int>& arr) {
//         int ans = 1;
//         int n = arr.size();
//         vector<int> dp(n + 1, -1);
//         return f(0, INT_MIN, arr, dp);
//     }






};