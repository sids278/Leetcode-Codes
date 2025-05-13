class Solution {
public:
    const int MOD = 1e9 + 7;

    // Changed map key to (int, int) to avoid repeated string overhead
    map<pair<int, int>, int> mp;

    int lengthAfterTransformations(string s, int t) {
        int slen = s.length();  // new key: length of s

        if (mp.find({slen, t}) != mp.end()) return mp[{slen, t}];
        if (s.empty() || t <= 0) return mp[{slen, t}] = s.length();

        int len = 0;
        for (char x : s) {
            int i = x - 'a';
            if (i + t > 25) {
                int changesLeft = t - (25 - i + 1);
                if (changesLeft <= 0) {
                    len = (len + 2) % MOD;  // "ab" adds 2
                } else {
                    len = (len + lengthAfterTransformations("ab", changesLeft)) % MOD;
                }
            } else {
                len = (len + 1) % MOD;
            }
        }
        return mp[{slen, t}] = len;
    }
};
