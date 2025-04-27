class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long ans = 0;
        int curr_minK = -1;
        int curr_maxK = -1;
        while (i < n && j < n) {
            if (nums[j] < minK || nums[j] > maxK) {
                j++;
                i = j;
                curr_minK = -1;
                curr_maxK = -1;
                continue;
            }
            if (nums[j] == minK) curr_minK = j;
            if (nums[j] == maxK) curr_maxK = j;
            if (curr_minK != -1 && curr_maxK != -1) {
                ans += min(curr_minK, curr_maxK) - i + 1;
            }
            j++;
        }
        return ans;
    }
};
