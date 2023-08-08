class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false; // if lengths are not the same then they can't be Isomorphic.
        
        unordered_map<char, char> mps; // mark chars from str1 to str2
        unordered_map<char, char> mpt; // mark chars from str2 to str1
        for(int i = 0; i < s.length(); i++) {
            /* if s[i] already occured in mps then if its not mapped to whats now in t[i] then it means we have something like
                a -> p
                a -> t instead of 'p' thus return false
            Similarly we check that if
                a -> p
                p -> t instead of 'a' thus return false */
            if(mps[s[i]] && mps[s[i]] != t[i]) return false;
            if(mpt[t[i]] && mpt[t[i]] != s[i]) return false;
            /* then map s[i] and t[i] as key, value pairs
            if they didn't occur in map or if they occured then they did follow the rules of being isomorphic */
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return true;
    }
};