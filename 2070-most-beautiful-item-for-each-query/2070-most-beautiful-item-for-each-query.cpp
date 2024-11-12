class Solution {
public:
    int find(int x, map<int, int>& mp) {
        auto it = mp.upper_bound(x);
        if (it == mp.begin()) return 0;
        --it;
        return it->second;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> mp;
        sort(items.begin(), items.end());

        int prevMax = -1;
        for (auto& x : items) {
            prevMax = max(prevMax, x[1]);
            mp[x[0]] = prevMax;
        }
        
        vector<int> ans;
        for (int x : queries) {
            if (mp.find(x) != mp.end()) {
                ans.push_back(mp[x]);
            } else {
                int f = find(x, mp);
                ans.push_back(f);
            }
        }
        
        return ans;
    }
};
