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
            int key = x.first;     // rabbit's answer
            int val = x.second;    // how many rabbits gave this answer
            int groupSize = key + 1;

            if (val % groupSize == 0) {
                ans += (val / groupSize) * groupSize;
            } else {
                ans += ((val / groupSize) + 1) * groupSize;
            }
        }

        return ans;
    }
};
