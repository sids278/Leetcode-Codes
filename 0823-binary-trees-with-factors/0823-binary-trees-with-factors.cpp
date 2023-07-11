class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod=1e9 +7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int64_t, int64_t> dp;
        int64_t ans = 0;

        for (auto x : arr) {
            dp[x]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
                }
            }
            ans += dp[arr[i]];
        }

        return ans%mod;
    }
};