class Solution {
public:
    int f(int indx,int prev,vector<vector<int>>& pairs,int n,vector<vector<int>>&dp){
		if(indx==n){return 0;}
        if(dp[indx][prev+1]!=-1){return dp[indx][prev+1];}
        int notPick=f(indx+1,prev,pairs,n,dp);
        int pick=INT_MIN;
        if(prev==-1||pairs[prev][1]<pairs[indx][0])
            pick=1+f(indx+1,indx,pairs,n,dp);
        return dp[indx][prev+1]=max(pick,notPick);
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		int n=pairs.size();
		sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
		return f(0,-1,pairs,n,dp);
	}
};