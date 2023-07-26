class Solution {
public:
    int counter(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;
    int left = 0, count = 0;

    for (int right = 0; right < n; right++) {
        freq[nums[right]]++;

        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return counter(nums,k)-counter(nums,k-1);
    }
};