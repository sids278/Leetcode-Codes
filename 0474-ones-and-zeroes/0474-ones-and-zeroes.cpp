class Solution {
public:
    int f(int i,vector<string>&strs,int m,int n,vector<vector<vector<int>>>&dp){
        if(i==strs.size())return 0;
        if(m==0&&n==0)return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int one=0;
        int zer=0;
        for(int k=0;k<strs[i].length();k++){
            if(strs[i][k]=='1')one++;
            else if(strs[i][k]=='0')zer++;
        }
        int pick = INT_MIN;
        if (m >= zer && n >= one)
        pick = f(i + 1, strs, m - zer, n - one,dp) + 1;

        int notPick = f(i + 1, strs, m, n,dp);
        return dp[i][m][n]=max(notPick, pick);
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(0,strs,m,n,dp);
    }
};