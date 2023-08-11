class Solution {
public:
    bool valid(int x, int t, vector<int>& v) {
        long long cnt = 0;
        for (auto n : v) {
            if (n % x == 0) cnt += n / x;
            else cnt += 1 + n / x;
        }    
                  
        if (cnt <= t) return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        auto sum = max_element(nums.begin(), nums.end()); // Use long long for sum
        int r = *sum;
        int mid;
        int ans = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (valid(mid, threshold, nums)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
