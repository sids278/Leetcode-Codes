class Solution {
public:
    const long MOD = 1e9 + 7;
    vector<int> nums;

    long check(int j, unordered_map<int, vector<int>>& mp) {
        long x = nums[j];

        // nums[i] == nums[j] * 2 ==> x must be even as nums[i] = 2*x_j
        if (mp.find(2 * x) == mp.end())
            return 0;

        auto& vec = mp[2 * x];

        // count how many indices < j
        long left = lower_bound(vec.begin(), vec.end(), j) - vec.begin();

        // count how many indices > j
        long right = vec.end() - upper_bound(vec.begin(), vec.end(), j);

        return (left * right) % MOD;
    }

    int specialTriplets(vector<int>& numsInput) {
        nums = numsInput;
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        long ans = 0;

        // fill positions map
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        // for each j, check triplets
        for (int j = 0; j < n; j++) {
            ans = (ans + check(j, pos)) % MOD;
        }

        return ans;
    }
};
