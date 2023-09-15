class Solution {
public:

    
    vector<int> partitionLabels(string s) {
         //ababcbacadefegdehijhklij
        int n = s.length();
        vector<int> v;
        int start = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        for (int i = 0; i < n;) {
            int end = mp[s[i]];
            for (int j = i; j <= end; j++) {
                end = max(end, mp[s[j]]);
            }

            v.push_back(end - start + 1);
            i = end + 1;
            start = i;
        }

        return v;
    }
};