//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // int solve(int i,int j,int &maxI,vector<vector<int>>&dp,vector<vector<int>>&mat){
    //     if(i>= mat.size()|| j>= mat[0].size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int right=solve(i,j+1,maxI,dp,mat);
    //     int down=solve(i+1,j,maxI,dp,mat);
    //     int diag=solve(i+1,j+1,maxI,dp,mat);
    //     if(mat[i][j]==1){
    //         cout<<"yello";
    //         dp[i][j]=1+min(right,min(diag,down));
    //         maxI=max(maxI,dp[i][j]);
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j]=0;
    //     }
    // }
      int solve(vector<vector<int>>&mat, int i, int j, int &maxi, vector<vector<int>>&dp){
        if(i>= mat.size()|| j>= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(mat, i, j+1, maxi,dp);
        int digonal = solve(mat, i+1, j+1, maxi,dp);
        int down = solve(mat, i+1, j, maxi,dp);
        
        if(mat[i][j]==1){
            dp[i][j] = 1 + min(right, min(digonal,down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else return dp[i][j]=0;
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxI=0;
        solve(mat,0,0,maxI,dp);
        
        return maxI;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends