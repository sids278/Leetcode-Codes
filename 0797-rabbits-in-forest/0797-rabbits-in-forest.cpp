class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        sort(answers.begin(), answers.end());
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (answers[i] == 0) {
                ans++;
                continue;
            }
            mp[answers[i]]++;
        }

        for (auto x : mp) {
            int val = x.second;
            int key = x.first;
            int groupSize = key + 1;
            int groups = (val + key) / groupSize;  // ceil(val / (key + 1))
            ans += groups * groupSize;
        }

        return ans;
    }
};
