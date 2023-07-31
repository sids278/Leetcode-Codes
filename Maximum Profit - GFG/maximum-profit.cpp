//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int b,int k,int A[], int N,vector<vector<vector<int>>>& dp){
        if(i==N)return 0;
        if(k==0)return 0;
        if(dp[i][b][k]!=-1)return dp[i][b][k];
        if(b){
            int pick=f(i+1,!b,k-1,A,N,dp)+A[i];
            int notPick=f(i+1,b,k,A,N,dp);
            dp[i][b][k]=max(pick,notPick);
            
        }
        else{
            int pick=f(i+1,!b,k-1,A,N,dp)-A[i];
            int notPick=f(i+1,b,k,A,N,dp);
            dp[i][b][k]=max(pick,notPick); 
        }
        return dp[i][b][k];
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(2, vector<int>(2*K+1, -1)));
        return f(0,0,2*K,A,N,dp);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends