class Solution {
public:
    string robotWithString(string s) {
        string t = "";
        string p = "";

        int n = s.length();
        vector<char> minRight(n);
        minRight[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minRight[i] = min(s[i], minRight[i + 1]);
        }

        int i = 0;
        while (i < n || !t.empty()) {
            if (!t.empty() && (i == n || t.back() <= minRight[i])) {
                // Perform 2nd operation only if t.back() <= remaining min in s
                p += t.back();
                t.pop_back();
            } else if (i < n) {
                // Always perform 1st operation if s is not empty
                t.push_back(s[i]);
                i++;
            }
        }

        return p;
    }
};
