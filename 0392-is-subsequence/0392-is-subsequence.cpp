class Solution {
public:
    bool f(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i==s.length())return dp[i][j]=true;
        if(j==t.length()&& i<s.length())return dp[i][j]=false;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=j;k<t.size();k++){
            if(s[i]==t[k]){
                if(f(i+1,k+1,s,t,dp)){
                    // cout<<i<<k<<j<<endl;
                    return dp[i][j]=true;
                }
            }
            
        }
        return dp[i][j]=false;
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s,t,dp);
    }
};