class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_map<int, vector<string>> mp;
        mp[0] = vector<string>{""};
        for (int len = 1; len <= n; len++) {
            vector<string> ans;
            for (int i = 0; i < len; i++) {          // i pairs inside (), len-1-i after
                for (auto &a : mp[i]) {
                    for (auto &b : mp[len-1-i]) {
                        ans.push_back("(" + a + ")" + b); //split into (A)B
                    }
                }
            }
            mp[len] = ans;
        }
        return mp[n];
    }
};