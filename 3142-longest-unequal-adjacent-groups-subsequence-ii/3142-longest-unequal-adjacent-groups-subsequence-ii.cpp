#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>()(p.first) ^ (hash<string>()(p.second) << 1);
    }
};

class Solution {
public:
    unordered_map<pair<string, string>, int, pair_hash> mp;
    vector<vector<int>> dp;
    vector<vector<int>> parent;

    int hamming(string s1, string s2) {
        if (s1.length() > s2.length()) return hamming(s2, s1);
        if (mp.find({s1, s2}) != mp.end()) return mp[{s1, s2}];
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return mp[{s1, s2}] = cnt;
    }

    int f(int i, int lastIdx, vector<string>& words, vector<int>& groups) {
        if (i == words.size()) return 0;
        if (dp[i][lastIdx + 1] != -1) return dp[i][lastIdx + 1];

        int take = 0;
        if (lastIdx == -1 || 
            (words[i].length() == words[lastIdx].length() &&
             groups[i] != groups[lastIdx] &&
             hamming(words[i], words[lastIdx]) == 1)) {
            take = 1 + f(i + 1, i, words, groups);
        }

        int notTake = f(i + 1, lastIdx, words, groups);

        if (take > notTake) {
            parent[i][lastIdx + 1] = i;
            dp[i][lastIdx + 1] = take;
        } else {
            parent[i][lastIdx + 1] = lastIdx;
            dp[i][lastIdx + 1] = notTake;
        }

        return dp[i][lastIdx + 1];
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        dp.assign(n, vector<int>(n + 1, -1));
        parent.assign(n, vector<int>(n + 1, -1));
        f(0, -1, words, groups);

        vector<string> res;
        int i = 0, lastIdx = -1;
        while (i < n) {
            int next = parent[i][lastIdx + 1];
            if (next == i) {
                res.push_back(words[i]);
                lastIdx = i;
            }
            i++;
        }
        return res;
    }
};
