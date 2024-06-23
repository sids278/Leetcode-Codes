class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<vector<string>> mp = {
            {}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"},
            {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"},
            {"t", "u", "v"}, {"w", "x", "y", "z"}
        };

        vector<string> result;
        string current;

        backtrack(digits, 0, mp, current, result);

        return result;
    }

private:
    void backtrack(const string& digits, int index, const vector<vector<string>>& mp,
                   string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (const string& letter : mp[digit]) {
            for (char c : letter) {
                current.push_back(c);
                backtrack(digits, index + 1, mp, current, result);
                current.pop_back();
            }
        }
    }
};