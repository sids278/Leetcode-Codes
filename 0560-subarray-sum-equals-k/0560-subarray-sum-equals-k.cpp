class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 0;
        long long sum = 0;
        unordered_map<long long, int> prefixSumFrequency; // Store frequency of prefix sums
        prefixSumFrequency[0] = 1; // Initialize to include the prefix sum of 0

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int requiredSum = sum - k;
            if (prefixSumFrequency.find(requiredSum) != prefixSumFrequency.end()) {
                ans += prefixSumFrequency[requiredSum];
            }
            prefixSumFrequency[sum]++;
        }

        return ans;
    }
};