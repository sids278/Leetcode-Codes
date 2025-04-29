class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0;
        long long cnt = 0;
        
        for (int j = 0; j < n; ++j) {
            if (nums[j] == maxE) cnt++;
            
            while (cnt >= k) {  // Only shrink when cnt is still >= k
                ans += (n - j); // All subarrays starting from i to j, j+1, ..., n-1 are valid
                if (nums[i] == maxE) cnt--;
                i++;
            }
        }
        // we didnt do something like count(k)-count(k-1) that actually gives you the exact k ones
        return ans;
    }
};