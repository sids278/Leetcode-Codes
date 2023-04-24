class Solution {
public:
    
    
    int dp[1100][1100];
    int mod=1e9+7;
    int f(int i, int j, vector<vector<int>> &v, string &target)
    {
        if(j==target.size()) return 1;
        if(i==v.size()) return 0;
        long long ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(v[i][target[j]-'a']) ans=(ans+(long long)v[i][target[j]-'a']*f(i+1,j+1,v,target)%mod)%mod;
        ans=(ans+f(i+1,j,v,target))%mod;
        return dp[i][j]=ans;      
    }
    int numWays(vector<string>& words, string target) 
    {
        int n=words[0].size();
        vector<vector<int>> v(n,vector<int> (26,0));
        for(auto word: words)
        {
            for(int x=0; x<n; x++)
            {
                v[x][word[x]-'a']++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return f(0,0,v,target);   
    }
    
};