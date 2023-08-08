class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int>v(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            v[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0)return false;
        }
        return true;
    }
};