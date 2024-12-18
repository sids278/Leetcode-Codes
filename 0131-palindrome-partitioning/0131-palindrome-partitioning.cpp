class Solution {
public:
    void dfs(int i, string s, vector<vector<int>>& dp, vector<vector<string>>& v, vector<string>& temp) {
        if (i == s.length()) {
            v.push_back(temp);
            return;
        }
        for (int end = i; end < s.length(); end++) {
            if (dp[i][end]) {
                temp.push_back(s.substr(i, end - i + 1));
                dfs(end + 1, s, dp, v, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> temp;
        dfs(0, s, dp, result, temp);
        return result;
    }
};
