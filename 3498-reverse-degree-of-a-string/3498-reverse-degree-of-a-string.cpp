class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int ans=1;
        for(int i=0;i<n;i++){
            char x=s[i];
            int val=x-'a';
            int actVal=26-val;
            ans=ans+actVal*(i+1);
        }
        return ans-1;
    }
};