//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long dp[1005][805];
    long long ncr(int n, int r)
    {
        if(n<r)return 0;
        if(n==r)return 1;
        if(r==0)return 1;
        if(r==1)return n;
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%int(1e9+7);
    }
    int nCr(int n, int r){
        // code here
        for(int i=0;i<=n+1;i++)for(int j=0;j<=r+1;j++)dp[i][j]=-1;
        return ncr(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends