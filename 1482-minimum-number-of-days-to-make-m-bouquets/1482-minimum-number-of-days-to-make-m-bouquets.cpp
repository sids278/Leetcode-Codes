class Solution {
public:
    bool valid(int d, vector<int>& a, int m, int k) {
        int ans = 0;
        int cnt = 0;
        for (auto x : a) {
            if (x > d) {
                ans += cnt / k;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans += cnt / k;
        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int64_t sizer = static_cast<int64_t>(m) * k;
        if (sizer > bloomDay.size()) return -1;
        int l = 1;
        auto maxElementIt = max_element(bloomDay.begin(), bloomDay.end());
        int r = *maxElementIt;
        int mi;
        int ans = 0;

        while (l <= r) {
            mi = (l + r) / 2;
            if (valid(mi, bloomDay, m, k)) {
                ans = mi;
                r = mi - 1;
            } else {
                l = mi + 1;
            }
        }
        return ans;
    }
};
